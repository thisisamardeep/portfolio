---
title: Empty base optimization  C++
published: true
tags: [ c++ ]
readtime: true
permalink: "/empty-base-class-optimization"
share-description: "Empty base optimization in  C++"
comments: false
---

First Let me share the cpp reference [EBO](https://en.cppreference.com/w/cpp/language/ebo) .

Ebo is only useful when you have a class which may sometimes have 0 or more than

zero members ie Like base classes passed during template instantiation in 

libraries.As per the principle of c++ policy based design we must pay only for

what we use.So if we use a data member which does not have any members and may

be sometimes empty it is usually better to use it as a base class and 

convert from has-a relationship to is-a relationship (provided we dont break 

or expose any other functionality or break abi or api).So when we say EBO it 

means we optimize for the total space used by a derived class when it inherits 

from a version of base class which does not have any data member.

Since we will use sizeof to show that we have optimized for space we need to use

#pragma pack(1) so pack the elements together so that we can prove our point.

We have 2 derived classes and they have data members of type Base_has_a_version1

and Base_has_a_version2.Version 1 has a int so it has some size.

First we use them as a "has a " relationship and then check the size of the

derived classes.
```cpp
#include <iostream>

#pragma pack(1)

class Base_has_a_version1 {
    int i;
};

class Base_has_a_version2 {
};


class Derived_has_a_version1 {
    Base_has_a_version1 b;
    char c;
};

class Derived_has_a_version2 {
    Base_has_a_version2 b;
    char c;
};

int main() {
    static_assert(sizeof(Derived_has_a_version1) == 5);
    
    // We can see that Derived_has_a_version2 has one member char but still 
   // size is 2 because 
   // sizeof(Derived_has_a_version2) =sizeof(char)+sizeof(Base_has_a_version2)
   // and sizeof(Base_has_a_version2) is 1 even though it is empty.
   // So we pay for size of Base_has_a_version2 just because it is a member.
    static_assert(sizeof(Derived_has_a_version2) == 2);
    return 0;
}


```
Now instead of using Base as a data member we use it a a public base class.


