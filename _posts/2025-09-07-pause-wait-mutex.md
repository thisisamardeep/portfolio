---
title: Mutexes for different types of waiting strategies
published: true
permalink: "/pause-wait-mutexes"
tags: [locks]
readtime: true
comments: false
---

Spin Mutexes quite used in concurrent programming, enabling threads to synchronize access to shared resources.
A spinlock is a simple lock that repeatedly checks if a lock is available, "spinning" in a loop until it can acquire the lock.
This avoids the overhead of kernel context switches but can waste CPU cycles if contention is high.
wait_mutex and pause_mutex are custom  mutex implementations using an atomic boolean flag for locking.

wait_mutex: Yielding to the Scheduler  

The wait_mutex uses an atomic boolean flag for locking. If the lock is already held, it calls std::this_thread::yield(),
hinting to the operating system to schedule another thread. This reduces CPU usage during contention but may introduce some latency.


pause_mutex: CPU-Friendly Spinning  

The pause_mutex also uses an atomic flag, but instead of yielding, it calls the _mm_pause() instruction inside its spin loop. This is a low-level 
CPU hint that improves performance on hyper-threaded processors by reducing power consumption and memory contention during busy-waiting.

If you know that the wait time is quite less use the pause_mutex since it does not give away cpu time slice.

Please see  the  spin mutex complete implementation [here](https://github.com/thisisamardeep/async_toolkit/blob/master/include/mutexes/spin-mutex.h)

Please see  the  pause mutex complete implementation [here](https://github.com/thisisamardeep/async_toolkit/blob/master/include/mutexes/pause-mutex.h) 


