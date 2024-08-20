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


unoredered map  each element is a pair of values.keys are not ordered.

How to insert into a map im c++

```cpp
int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee"; // first way
    m.insert(std::make_pair(23, "ee"));// second way
    m.insert(std::pair(34, "333")); // third way
    m.insert({2, "err"});  //fourth way
    return 0;
}
```

How to loop over all item of a unoredered map c++
We can use iterators.

```cpp
  std::unordered_map<int, std::string> m;
    m[1] = "ee"; // first way
    m.insert(std::make_pair(23, "ee"));// second way
    m.insert(std::pair(34, "333")); // third way
    m.insert({2, "err"});  //fourth way
// For maps we need to use ++it or it++ .We cannot use it=it+! since map elements are not 
// stored in contiguos mem locations.
    std::unordered_map<int, std::string>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << std::endl;// You get all keys here
        std::cout << it->second << std::endl; // you get all values here
    }
    return 0;
```

Second way to loop over all items of a map

We can use range based for loop. Each lement is a pair.
```cpp
int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee"; // first way
    m.insert(std::make_pair(23, "ee"));// second way
    m.insert(std::pair(34, "333")); // third way
    m.insert({2, "err"});  //fourth way
    // In this way copies are made
    for (std::pair<int, std::string> item: m) {
        std::cout << item.first << std::endl;
    }
    // In this way no copies are made.
    for (auto& item: m) {
        std::cout << item.first << std::endl;
    }
    return 0;
}
```