---
title: vectors in c++
published: false
share-description: ""
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/vectors-in-cpp"
share-description: "vectors in c++"
comments: false
---


Just reverse the vector

vector<int> test = {1, 2, 3,4,5, 6};

    std::reverse(test.begin(), test.end());

result {6,5,4,3,2,1}

=======================================================

Reverse vector in part from front


    vector<int> test = {1, 2, 3, 4, 5, 6};

    std::reverse(test.begin() + 2, test.end());

//    { 1, 2, 6, 5, 4, 3 }

========================