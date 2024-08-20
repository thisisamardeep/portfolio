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

normal oredered map(values are sorted by key)

unoredered map (values are not sorted by key)



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
How to loop over all item of a  map c++
We can use iterators.

```cpp

int main() {
    std::map<int, std::string> m;
    m[1] = "ee"; // first way
    m.insert(std::make_pair(23, "ee"));// second way
    m.insert(std::pair(34, "333")); // third way
    m.insert({2, "err"});  //fourth way

    for (it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << std::endl;// You get all keys here
        std::cout << it->second << std::endl; // you get all values here

    }
    return 0;
}




```
Second way to loop over all items of a map
use range based for loop.
Each element is a pair.

```cpp
int main() {
    std::map<int, std::string> m;
    m[1] = "ee"; // first way
    m.insert(std::make_pair(23, "ee"));// second way
    m.insert(std::pair(34, "333")); // third way
    m.insert({2, "err"});  //fourth way

    for (std::pair<int, std::string> item: m) {
        std::cout << item.first << std::endl; // we get all keys here
    }
    return 0;
}


```