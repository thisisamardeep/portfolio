---
title: My thoughts on Spsc Queue
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

Case 2) The Objects which will be pushed and pulled are in 2 or more cache line.(They are more than 64 bytes)

In this post we will handle only Case 1 and give pointers how to handle case 2.There is no general solution for case 2.
It is usually context specific and requirement specific.

First we will design the spsc queue is ancient way and then benchmark it later with atomics.At end using atomics
we will create a queue which is faster than the general purpose boost spsc queue.

First let us start simple we build a queue using mutexes plain old way.
We have 2 pointers push and pop.Using mutexes we lock the entry into the push and pop functions.
We use modulo operation since we need to reuse Queue like a circular buffer.(Almost similar to the way linux kernel
manages the tcp packets and pushes them to user space .)
The push cursor has the index where the element will be inserted and pop has the index where
it will be removed.We need to handles cases when queue is full or empty.
This is a wait free queue  so it means if we are not able to push or pop we return immediately.

Please see the complete implementation of spsc using locks [here](https://github.com/thisisamardeep/async_toolkit/blob/master/include/mutexes/spin-mutex.h)

