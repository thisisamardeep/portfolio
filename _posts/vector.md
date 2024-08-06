---
title: vectors in c++
published: false
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
This reverses the vector in place.It does not return anything.
=======================================================

Reverse vector in part from front


    vector<int> test = {1, 2, 3, 4, 5, 6};

    std::reverse(test.begin() + 2, test.end());

//    { 1, 2, 6, 5, 4, 3 }

========================

    vector<int> inp = {7, 5, 9, 2, 8};
    vector<int> inp11 = {7, 5, 9, 112, 8};
    std::swap(inp[0], inp11[3]);
This works swap can swap array but also swap elements of same or different vectors
========================================

How to  concat 2 arrays in cpp

std::vector<int> first = {1, 2, 3};
std::vector<int> second = {4, 5};
              -->
    first.insert(first.end(), --> the iterator of the first array at the end of which new array will be inserted.
second.begin(),  --> The begin iterator of the array to be inserted
second.end())     --> The end iterator of the array to be inserted

======================================


Module operator 
x 3  y 1

	std::cout << "The remainder is: " << x % y << '\n'; 1 
================================================
create a vector of size n with all values as 10

vector<int> vect(n, 10); 

==========================

Delete last element
myvector.pop_back();

return notthing
================
removes all elements and makes size 0
retrusn none

myvector.clear();



=====================