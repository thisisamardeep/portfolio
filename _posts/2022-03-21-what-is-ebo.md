---
title: Empty base optimization  C++
published: false
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

or expose any other functionality or break our abi or api).So when we say 

EBO it means we optimize for the total space used by a derived class when it inherits 

from a version of base class which does not have any data member.

Since we will use sizeof to show that we have optimized for space we need to use

#pragma pack(1) so  we pack the elements together so  we can prove our point.

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
Now instead of using Base as a data member we use it as a public base class.

```cpp

class Base_is_a_version1 {
    int i;
};

class Derived_is_a_version1 : public Base_is_a_version1 {
    char c;
};

class Base_is_a_version2 {
};

class Derived_is_a_version2 : public Base_is_a_version2 {
    char c;
};

int main() {
    static_assert(sizeof(Derived_is_a_version1) == 5);
    // Here we pay only what we use.
    // our class has only 1 char so size is 1.
    static_assert(sizeof(Derived_is_a_version2) == 1);
    return 0;
}

```

This is a toy example and might look not much beneficial but if we have 1000's 

of instances then  this gets added up.Now let us look at some real life uses.

See the unique pointer implementation .The unique pointer uses either the 

default delete or user supplied deleter function.See the link [MSVC STL](https://learn.microsoft.com/en-us/cpp/standard-library/unique-ptr-class?view=msvc-170)

The default deleter does not add any extra space when it is used.If you are 

a nerd.. which i am not you can look into this actual memory header file. 

[HEADER MSVC](https://github.com/microsoft/STL/blob/main/stl/inc/memory#L1273)