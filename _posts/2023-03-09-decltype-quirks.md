---
title: Decltype in Depth
published: true
tags: [ c++ ]
readtime: true
permalink: "/decltype-quirks"
share-description: "Decltype in Depth"
comments: false
---

First Let me share  the cpp reference [DeclType](https://en.cppreference.com/w/cpp/language/decltype)  . 
It is clear from reference that decltype has 2 syntaxes decltype ( entity ) and decltype ( expression ).
And it has different rules it follows to deduce types.
Having a good understanding of decltype in critical when you deal with super complex template code
in libraries since we need to know how compiler is deducing the return types.
Consider a integer variable and let us try to use decltype on it.
i is a variable of type int and (i) is a expression of type int so it is treated differently and we get a reference to int.
Similarty (obj) and obj are different.

```cpp

#include "cassert"
int main() {

    int i = 67;
    assert((std::is_same_v<decltype(i), int>));
    assert((std::is_same_v<decltype((i)), int &>));

    Foo obj{};
    assert((std::is_same_v<decltype(obj), Foo>));
    assert((std::is_same_v<decltype((obj)), Foo &>));

return 0;
}

```

decltype(auto) can be used to "perfect forward" a return value.
In template code or for that matter in any code our ability or non ability to return a reference 
makes all the difference.

Consider the below example.We have a non template function and it has a static variable.We  need to be 
able to return the static variable since we know we will be incrementing it.


```cpp
int &TestFun() {
    static int i = 0;
    std::cout << i << std::endl;
    return i;
}

int main() {
    TestFun();
    TestFun()++;
    TestFun();
    return 0;
}

```

Basically we need to return a reference to i since we know we need to increment it.
The problem comes when we have such logic in a templated function.
Let us try to use auto in this function so that we can template it later and then see what we get.



```cpp
auto TemplTestFun() {
    static int i = 0;
    std::cout << i << std::endl;
    return i;
}

int main() {

    TemplTestFun();
    TemplTestFun()++;  // This does not compile since TemplTestFun returns int by value
    TemplTestFun();

    return 0;
}

```

Now we use decltype(auto) and see what we get.
See this link  [Return type deduction](https://en.cppreference.com/w/cpp/language/function#Return_type_deduction)


```cpp
decltype(auto) TemplTestFun() {
    static int i = 0;
    std::cout << i << std::endl;
    return i;
}

int main() {

    TemplTestFun();
    TemplTestFun()++; // This does not compile since decltype(auto) deduces the type as int and not int&
    TemplTestFun();

    return 0;
}

```


```cpp
decltype(auto) TemplTestFun() {
    static int i = 0;
    std::cout << i << std::endl;
    return (i);  // (i) is a parentheszed expression 
}

int main() {

    TemplTestFun();
    TemplTestFun()++; // This compiles now the deduced type in int &
    TemplTestFun();

    return 0;
}

```

Now let us convert this function to a template function so that we can see the real power of decltype.
We use trailing return type syntax .See the below code .The assembly code produced by gcc 13.2 is also there.


```cpp
template<typename T>
auto TemplTestFun(T a) -> decltype(auto) {
    static T i = 0;
    std::cout << i << std::endl;
    return (i);
}

int main() {

    TemplTestFun(2);
    TemplTestFun(2)++;
    TemplTestFun(2);

    TemplTestFun(2.4);
    TemplTestFun(2.4)++;
    TemplTestFun(2.4);

    return 0;
}
/**
 * TemplTestFun<int>(int)::i:
        .zero   4
decltype(auto) TemplTestFun<int>(int):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR TemplTestFun<int>(int)::i[rip]
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        mov     eax, OFFSET FLAT:TemplTestFun<int>(int)::i
        leave
        ret
TemplTestFun<double>(double)::i:
        .zero   8
decltype(auto) TemplTestFun<double>(double):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        movsd   QWORD PTR [rbp-8], xmm0
        mov     rax, QWORD PTR TemplTestFun<double>(double)::i[rip]
        movq    xmm0, rax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(double)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        mov     eax, OFFSET FLAT:TemplTestFun<double>(double)::i
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        mov     edi, 2
        call    decltype(auto) TemplTestFun<int>(int)
        mov     edi, 2
        call    decltype(auto) TemplTestFun<int>(int)
        mov     edx, DWORD PTR [rax]
        add     edx, 1
        mov     DWORD PTR [rax], edx
        mov     edi, 2
        call    decltype(auto) TemplTestFun<int>(int)
        mov     rax, QWORD PTR .LC0[rip]
        movq    xmm0, rax
        call    decltype(auto) TemplTestFun<double>(double)
        mov     rax, QWORD PTR .LC0[rip]
        movq    xmm0, rax
        call    decltype(auto) TemplTestFun<double>(double)
        movsd   xmm1, QWORD PTR [rax]
        movsd   xmm0, QWORD PTR .LC1[rip]
        addsd   xmm0, xmm1
        movsd   QWORD PTR [rax], xmm0
        mov     rax, QWORD PTR .LC0[rip]
        movq    xmm0, rax
        call    decltype(auto) TemplTestFun<double>(double)
        mov     eax, 0
        pop     rbp
        ret
.LC0:
        .long   858993459
        .long   1073951539
.LC1:
        .long   0
        .long   1072693248
 * 
 */


/**
* 
 * Types deduced by the compiler are
 * 
 * template<> auto TemplTestFun<int>(int a) -> int & {
    static int i = 0;
    std::cout << i << std::endl;
    return (i);
}
template<> auto TemplTestFun<double>(double a) -> double & {
    static double i = 0;
    std::cout << i << std::endl;
    return (i);
}
*/
```
It is clear from the compiler output that 2 TemplTestFun functions get created.
One returns int & and other double & .
This looks trivial here but when you have complex template functions and types moving all
around it becomes critical to know what decltype does and when.


