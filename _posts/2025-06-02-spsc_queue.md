---
title: My thoughts on Spsc Queue with 100 million test that beats Boost
published: true
permalink: "/spsc_queue"
tags: [mutex,contention]
readtime: true
comments: false
---

Spsc queue is one of the most widely used data structures in low latency systems.
Broadly there are can be 2 types of queue bounded or unbounded.Since we almost always want full control of the 
memory we use bounded queue 99% of the time.Among the bounded queue there can be 2 types of Queues.

Case 1) The Objects which will be pushed and pulled can fit inside a single cache line

Case 2) The Objects which will be pushed and pulled are in 2 or more cache lines.(They are more than 64 bytes)

In this post we will handle only Case 1 and give pointers how to handle Case 2.There is no general solution for Case 2.
It is usually context specific and requirement specific.

First we will design the spsc queue in ancient way and then benchmark it later with atomics.At end using atomics
we will create a queue which is faster than the general purpose boost spsc queue and then benchmark  3 queues 

1) Our Custom Queue with Locks
2) Boost Lock Free Spsc
3) Our Custom Queue with Atomics

We will show with benchmark that atomic queue gives almost 3 times better latency than the queue with locks and 2 times better
performance as compared to Boost spsc.


First let us start simple we build a queue using mutexes plain old way.
We have 2 pointers push and pop.Using mutexes we lock the entry into the push and pop functions.
We use modulo operation since we need to reuse Queue like a circular buffer.
The push cursor has the index where the element will be inserted and pop has the index where
it will be removed.We need to handle cases when queue is full or empty.
This is a wait free queue  so it means if we are not able to push or pop we return immediately.

Please see the complete implementation of spsc using locks [here](https://github.com/thisisamardeep/async_toolkit/blob/master/include/mutexes/spin-mutex.h)



Now we will come up with the atomic queue.We will try to explain atomic queue is detail since memory model is tough to understand
especially if you have not read the standard in depth .When we use atomics we need to understand that the penalty is greatest for the 
default order.Memory order and Cache line alignment is the core reason why our atomic queue is fast along with  cached custom
index pointers.

We use 4 pointers 2 are cached (and non atomic )and 2 are atomic.QueueAtomic stores elements in a contiguous buffer and uses two indices: 
a producer index and a consumer index.The producer advances the push index and constructs objects in place; the consumer 
reads objects, destroys them, and advances the pop index.

Relaxed Ordering --> This means that compiler and processor are free to move around instructions as they see fit but only
the specific operation is guaranteed to be atomic

Acquire Release Barrier --> This means we are trying to create a fence in which we have well defined memory model.
Well defined means from each cpu core point of view.C++11 has a well defined memory model which all compilers and processors
need to follow.

We need to note that instructions reordering can happen both and compiler level and processor level.
Many times we generally generate the assembly from the compiler and try to look into it for bugs or performance reasons but
dont look inside what the processor does.If you have linux machine with intel cpu you can disable prefetching and see the instructions
actually being executed.This helps a lot in understanding atomics when we need to reason why we have cache line misses.For some cpus they fetch 
in 2 chunks of cache lines so you might need to double your alignment to keep cache coherence traffic low.For my intel cpu i 
need to double the hardware alignnment to get best benchmarks.For your cpu it might be different.

In our queue we have 2 acquire release barriers.For push_index we need to make sure that all 
loads are able to see all stores and the side effects of stores.What this means for our queue is that suppose we have 2 threads
one is at this line

push_index_cache = _push_index.load(std::memory_order_acquire); --> First thread is executing here

and other thread is at this line

_push_index.store(_push_index_new, std::memory_order_release);   --> Second thread is executing here

Since this is a barrier so to have a well defined world view we need to make sure that load operation is able to see all variables
atomic/non atomic before the store operation.In our case we need happens before relation we dont need total ordering so side effects are less.
Please read standard for the exact definition of  side effects and invariants.It is much more complex than what i mentioned here but this is the  core idea.
So to have a well defined world view we create 2 barriers.Rest all atomic operations are kept relaxed.
We do not need sequential consistency here since we dont need total ordering.

Other than atomics the only thing used here in alignment to make sure that there is less cache misses.
One of the reasons we are able to beat boost is alignment  second reason being cached cursors.

The reason why we keep capacity as power of 2 is since some times we use bitwise and instead of modulu for managing the counters but 
that may or may not be possible in all cases so it is not used here.The Queue is developed with intention that anyone can just use it as
a drop in replacement.
Since And operation is just 1-2  cpu cycles you can get generally get better performance using bitwise and.


Now we come to the case 2.Our queue will also work where size of elements is more than cache line size but the benchmarks will
not be good.If the size of elements is more than cache line size then the cache eviction will increase and you get more memory traffic.
One of the widely used ways is to use custom arena allocators.The core concept is that in the queue we just pass the address of the objects.
So while popping from the queue we also copy the address into another Queue which has a consumer which is pinned to another thread.
This pinned thread keep deallocating the objects in the arena allocator(generally we dont call free in hot path).
These designs are almost always application specific .What works in one project will almost never work in another project .

Please see the complete implementation of spsc using atomics [here](https://github.com/thisisamardeep/async_toolkit/blob/master/include/mutexes/spin-mutex.h)

Please find the below report of benchmark Testing.Please note for benchmark we have pinned threads to avoid noise due to cpu switching.
```text

Queue                      Time taken to push and then pop 100 Million integers(in seconds) 
QueuewithAtomics                                   6.94 s    
SpscBoost                                          10.7 s  
QueuewithLocks                                     16.3 s

Actual benchmark report
Run on (8 X 3800.11 MHz CPU s)
CPU Caches:
L1 Data 48 KiB (x4)
L1 Instruction 32 KiB (x4)
L2 Unified 1280 KiB (x4)
L3 Unified 12288 KiB (x1)

--------------------------------------------------------------------------------
Benchmark                                      Time             CPU   Iterations
--------------------------------------------------------------------------------
BM_QueueAtomic/iterations:5/real_time       6.94 s         0.018 s             5
BM_BoostSpsc/iterations:5/real_time         10.7 s         0.018 s             5
BM_QueueLocks/iterations:5/real_time        16.3 s         0.019 s             5

```
