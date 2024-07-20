---
title: queues in c++
published: true
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/queues-in-cpp"
share-description: "queues in c++"
comments: false
---

Queue is First in First out. Queue elements are pushed in the back of the queue
and come out from front of the queue. Removal of elements is from the Front
Adding of elements is from the back of the Queue. cpp we can access elements
from the back of the Queue or front of the Queue.

```cpp
#include "queue"
int main() {
    std::queue<int> numbers;
    numbers.push(45); // Add element to the back of the Queue.
    auto front_of_queue = numbers.front(); // Does not work if queue is empty
    auto back_of_queue = numbers.back(); // Does not work if queue is empty
    numbers.pop();// Removes elements from front of the queue.No return value
    return 0;
}
```


Hlow