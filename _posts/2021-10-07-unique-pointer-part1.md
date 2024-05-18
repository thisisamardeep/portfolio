---
title: Unique Pointer Part1 
published: true
tags: [ c++ ]
readtime: true
permalink: "/unique-pointer-part-1"
share-description: Custom Unique Pointer 
comments: false
---

In this series we will try to implement some of the properties of unique 

pointer.In this part part 1 we will implement the below 2 properties of 

unique pointers.

1) When the pointer goes out of scope it calls the destructor

2) We can use arrow operator and deferencing operator on the object of
unique pointer.


First we will implement only the property 1.We need to make sure that when

instance of unique pointer goes out of scope we need to call delete.

As of now we will use default delete.But before that we need to store the

pointer to the instance somewhere so that we can call delete on it.


```cpp
struct Test {
    int i;
         
    explicit operator float() const {
        return i;
    }
};
 
Test t{1};
auto f = static_cast<float>(t);

```

See the assembly code below with each line explained


```cpp
lea     rax, [rbp-8]  //This is a just a address copy in assembly terms
mov     rdi, rax       // This is a just a copy in assembly terms
call    Test::operator float() const  
//See a call happens and branches to new address in assembly terms.
movd    eax, xmm0
mov     DWORD PTR [rbp-4], eax

```
This call happens at run time.So it is clear then static cast 

can have run time implications. I have generated all assembly with optimizations 

disabled.For a simple example like this compiler can optimize away 

but in large production code bases with structs being passed around things can be 

very different.
