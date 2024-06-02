---
title: sets in c++
published: false
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/sets-in-cpp"
share-description: "sets in c++"
comments: false
---
std::set<string> stores elements in sorted order.
so set is techinically a ordered set.

a set can have only unique elements.

So it means set cannot have duplicate elements.

std::set<string> s;

s.insert("abc");

s.insert("abc1");

s.insert("abc1");

 --> inserts elements into a set

auto it = s.find("abc");  --> returns a iterator.
Used to find element of a set.

Loop over all elements of a set

    for(auto ss:s){
        std::cout << ss << std::endl;
    }

Loop over all elements of a set using iterators

    for (auto i = s.begin(); i != s.end(); i++) {
        std::cout << *i << std::endl;
    }


s.erase("abc");  --> Removes elements from a set