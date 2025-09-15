---
title: My thoughts on Mutex Internals and Custom need based Mutex(Hot/Cold)
published: true
permalink: "/thoughts-about-smart-mutexes"
tags: [mutex,contention]
readtime: true
comments: false
---

We almost trust std::mutex like a black box.We usually take a mutex ,lock it (now we assume that no other thread can acquire it) ,do our critical 
section work and then unlock it.Sometimes in high contention or hot path cases it becomes much more important to know what linux kernel is doing 
behind the scenes.Mutex uses a syscall called futex internally which provides a user space api to talk to the kernel .

First we will run a small  multi threaded code and then use strace to peek behind what is happening so we understand what problem we are trying to
solve.Then we will build a custom mutex which we can use in hot path or contention cases (but not both).
The goal is that if we know that path is hot and contention time is very less then no need to go to kernel space via futex and if we know that path is cold then we use condition variables to put the
thread to sleep so that cpu is kept free so that we can scale to much more threads than cores in our cpu if we know that threads will wait  a lot.
We can scale up our thread count a lot if we know that our threads dont fight for resources.


```cpp

#include <cassert>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


int main()
{
    std::mutex m;
    int result = 0;
    std::vector<std::thread> my_threads;
    for (int i = 0; i < 8; i++)
    {
        my_threads.emplace_back([&m,&result]()
        {
            m.lock();
            for (int i = 0; i < 100; i++)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));

                result++;
            }
            m.unlock();
        });
    }

    for (auto& t : my_threads)
    {
        t.join();
    }
    std::cout << result << std::endl;
    assert(result ==800);
    return 0;
}



```

if you run the above code you will see logs like this.

```
futex(0x762c7d3ff990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37916, NULL, FUTEX_BITSET_MATCH_ANY) = 0
futex(0x762c7cbfe990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37917, NULL, FUTEX_BITSET_MATCH_ANY) = 0
futex(0x762c7c3fd990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37918, NULL, FUTEX_BITSET_MATCH_ANY) = 0
futex(0x762c7bbfc990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37919, NULL, FUTEX_BITSET_MATCH_ANY) = 0
futex(0x762c7b3fb990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37920, NULL, FUTEX_BITSET_MATCH_ANY) = 0
munmap(0x762c7cbff000, 8392704)         = 0
futex(0x762c7abfa990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37921, NULL, FUTEX_BITSET_MATCH_ANY) = 0
munmap(0x762c7c3fe000, 8392704)         = 0
futex(0x762c7a3f9990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37922, NULL, FUTEX_BITSET_MATCH_ANY) = 0
munmap(0x762c7bbfd000, 8392704)         = 0
futex(0x762c79bf8990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 37923, NULL, FUTEX_BITSET_MATCH_ANY) = 0



```

This is a clear indication that std::mutex keeps threads waiting on futexes.
But sometimes we dont want threads to wait we want them to spin instead and sometimes we dont want threads to wait on futexs but instead
wait on condition variables and be woken up by user code when needed.std::mutex being a general purpose mutex does not provide this level of
granularity.

```
Futex calls take most of the time.

% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
98.21    0.012958        1439         9           futex
```


Now we will run the same code but with a spin mutex which spins instead of making futex syscalls.


```cpp

#include <cassert>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


int main()
{
    async_toolkit::spin_mutex m;
    int result = 0;
    std::vector<std::thread> my_threads;
    for (int i = 0; i < 8; i++)
    {
        my_threads.emplace_back([&m,&result]()
        {
            m.lock();
            for (int i = 0; i < 100; i++)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));

                result++;
            }
            m.unlock();
        });
    }

    for (auto& t : my_threads)
    {
        t.join();
    }
    std::cout << result << std::endl;
    assert(result ==800);
    return 0;
}



```
The time spent on futex syscall has reduced by 65%.
```
strace log.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
65.88    0.002410         482         5           futex
```
This clearly shows that much less futex calls are made and time spent has decreased by almost 65%.

The implementation of spin_mutex is quite simple.spin_mutex is just a RAII over a atomic flag.
When a thread acquires a lock it first checks the condition.If the condition is false we just use the gcc instruction
_mm_pause to tell the cpu to enter into a pause state. At the hardware level this is a SSE2 instruction set extension.
Kindly note we cannot and should not use yield here since it gives the time slice of the current thread to the next thread.
Yield usually causes a context switch which we want to avoid.Pause is a hardware instruction which pauses the thread but does not
ask the os to put it in the least priority or schedule another thread or give up its time slice.

Please see the complete implementation [here](https://github.com/thisisamardeep/async_toolkit/blob/master/include/mutexes/spin-mutex.h) 

