---
title: maps in c++
published: true
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/maps-in-cpp"
share-description: "maps in c++"
comments: false
---
There are 2 types of map

normal map(values are sorted by key)

unoredered map (values are not sorted by key)

This descriways ways to insert/update/delete/search elements from both types of maps.


map // unoredered map  each element is a pair of values.

How to insert into a map im c++

```cpp
#include "vector"

int main() {
       std::map<int, std::string> m;
        m[1] = "ee"; // first way
        m.insert(std::make_pair(23, "ee"));// second way
        m.insert(std::pair(34, "333")); // third way
        m.insert({2, "err"});  //fourth way

    return 0;
}
```

How to insert into a unordered map im c++

```cpp
#include <unordered_map>


int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee";
    m.insert(std::make_pair(23, "ee"));
    m.insert(std::pair(34, "333"));
    m.insert({2, "err"});
    return 0;
}
```

How to iterate all the elements of a map c++

```cpp
#include <unordered_map>


int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee";
    m.insert(std::make_pair(23, "ee"));
    m.insert(std::pair(34, "333"));
    m.insert({2, "err"});
    return 0;
}

// working types
// how to iterate over a map  using for loop and auto keyword.

int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee";
    m.insert(std::make_pair(23, "ee"));
    m.insert(std::pair(34, "333"));
    m.insert({2, "err"});
    for (auto i: m) {
        std::cout << i.first << std::endl;


        assert((is_same<decltype(i), pair<const int, string>>::value));
        assert((is_same<decltype(i.first), const int>::value));
        assert((is_same<remove_const<remove_reference<decltype(i.first)>::type>::type, int>::value));
        assert((is_same<decltype(i.second), string>::value));


    }

    return 0;
}
```