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
"static" keyword has many meanings in the context of c++ compiler.You can mark a

variable as private, function call spanning,per call data.Just because static_cast 

has the word static many times we assume that it knows at compile time what is going 

to happen at run time .First static keyword has no relation with static_cast.

Every expression in c++ has 2 independent attributes.. type of the expression and 

its value category.(lvalue,rvalue,prvalue,glvalue,xvalue). static_cast(if successful) 

always changes  the type of the expression and gives a new expression which has the 

new type.But it may or may not change the value category of the expression. This is 

clear from  the standard [static _cast](https://en.cppreference.com/w/cpp/language/static_cast).

Also note that static_cast uses a combination of implicit and user defined

conversions so it is always advisable to use it explicitly otherwise it 

might not do what you want it to do.

So if we use static cast we need to also take into account the value category of the 

input and output expression. static_cast being a explicit cast performs some compile 

time checks and compiler will warn whether it sees any issues in conversion but there

are some run  time aspects to it.

First we see how static cast works for numerics.

```cpp
int main() {
    float f;
    auto i = static_cast<int>(f);
    return 0;
}

```

See the always reliable assembly  code


```cpp
movss   xmm0, DWORD PTR [rbp-4]
cvttss2si       eax, xmm0
mov     DWORD PTR [rbp-8], eax
```


So we just convert from float to int using the conversion instruction cvttss2si and

place it in eax. Then we move to rbp-8 location since we have 2 local variables .. 

f and i since assembly uses offsets to track the location of these variables.

Also note static_cast operator cannot cast away the const, volatile,

or __unaligned attributes. Now let us see how we can convert a user defined type

to float using static cast.


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
