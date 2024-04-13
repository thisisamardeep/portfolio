---
title: Majority Element in a Array
published: true
tags: [ leetcode ]
readtime: true
permalink: "/majority-element"
share-description: Majority Element
comments: false
---
W

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
