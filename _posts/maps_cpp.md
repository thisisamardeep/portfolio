---
title: maps in c++
published: true
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/maps-in-cpp"
share-description: "maps in c++"c++ map
comments: false
---
There are 2 types of map

normal map(values are sorted by key)

unoredered map (values are not sorted by key)

This describes ways to insert/update/delete/search elements from both 
types of maps.


List all possible ways to insert into ordered map.
How to insert into a map im c++

```cpp
#include "vector"

int main() {
       std::map<int, std::string> m;
    m[1] = "ee"; // first way
    m.insert(std::make_pair(23, "ee"));// second way
    m.insert(std::pair(34, "333")); // third way
    m.insert({2, "err"});  //fourth 

    return 0;
}
```
