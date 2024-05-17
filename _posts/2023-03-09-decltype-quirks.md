---
title: Decltype in Depth
published: true
tags: [ c++ ]
readtime: true
permalink: "/decltype-quirks"
share-description: "Decltype in Depth"
comments: false
---

First Let me share the cpp
reference [DeclType](https://en.cppreference.com/w/cpp/language/decltype)  .
It is clear from reference that decltype has 2 syntaxes decltype ( entity ) and
decltype ( expression ).
And it has different rules it follows to deduce types.
Having a good understanding of decltype in critical when you deal with super
complex template code
in libraries since we need to know how compiler is deducing the return types.
Consider a integer variable and let us try to use decltype on it.
i is a variable of type int and (i) is a expression of type int so it is treated
differently and we get a reference to int.
Similarly (obj) and obj are different.

First let us try to understand what auto can and cannot do.It will be easy
to understand why we need decltype(auto) .

All below uses are self explanatory.

```cpp

const int &get_int_first_example() {
    int *t = new int(45);
    return *t;
}

const int &get_int_second_example() {
    int *t = new int(45);
    return *t;
}

const int &get_int_third_example() {
    int *t = new int(45);
    return *t;
}

const int &get_int_fourth_example() {
    int *t = new int(45);
    return *t;
}

const int &get_int_fifth_example_decltype_auto() {
    int *t = new int(45);
    return *t;
}
// auto is never going to deduce a reference
int main() {
    auto first_example = get_int_first_example();
    static_assert(std::is_same<decltype(first_example), int>::value);

    const auto second_example = get_int_second_example();
    static_assert(std::is_same<decltype(second_example), const int>::value);

    const auto &third_example = get_int_third_example();
    static_assert(std::is_same<decltype(third_example), const int &>::value);

    // All the above 3 cases auto on it own was not able to deduce const or
    // reference correctly

// as per autos type dedution rules since it is reference so it must be const    

    auto &fourth_example = get_int_fourth_example();
    static_assert(std::is_same<decltype(fourth_example), const int &>::value);
    
    
    //decltype is able to deduce the correct return type
    decltype(auto) fifth_example = get_int_fifth_example_decltype_auto();
    static_assert(std::is_same<decltype(fifth_example), const int &>::value);
    
    
    return 0;
}
```

decltype can be very useful in perfect returning.
```cpp


const int &get_value_example1() {
    int *t = new int(45);
    return *t;
}

auto get_value_wrapped_example1() {
    return get_value_example1();
}

const int &get_value_example2() {
    int *t = new int(45);
    return *t;
}

decltype(auto) get_value_wrapped_example2() {
    return get_value_example2();
}

int main() {
    // here due to normal type deduction rules first_example is deduced as int

    decltype(auto) first_example = get_value_wrapped_example1();
    static_assert(std::is_same<decltype(first_example), int>::value);

//decltype(auto)   makes sure that type is perfectly returned from the 
//wrapped function
    decltype(auto) second_example = get_value_wrapped_example2();
    static_assert(std::is_same<decltype(second_example), const int &>::value);

    return 0;
}


```


Consider a integer variable and let us try to use decltype on it.
i is a variable of type int and (i) is a expression of type int so it is 
treated differently and we get a reference to int. Similarly (obj) and obj 
are different.
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
In template code or for that matter in any code our ability or non ability to
return a reference
makes all the difference.

Consider the below example.We have a non template function and it has a static
variable.We need to be
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

Basically we need to return a reference to i since we know we need to increment
it.
The problem comes when we have such logic in a templated function.
Let us try to use auto in this function so that we can template it later and
then see what we get.

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
See this
link  [Return type deduction](https://en.cppreference.com/w/cpp/language/function#Return_type_deduction)

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

Now while returning we replace i with (i) and now the deduced type is int &.

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

Now let us convert this function to a template function so that we can see the
real power of decltype.
We use trailing return type syntax .See the below code .The assembly code
produced by gcc 13.2 is also there.

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
 *  TemplTestFun<int>(int)::i:
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
At the assembly level there is no difference between int and int &.It only
differs at c++ level.
At the asembly level for reference it returns the off set see this line
mov eax, OFFSET FLAT:TemplTestFun<int>(int)::i.So technically move just copies
the offset value to eax.
This looks trivial here but when you have complex template functions and types
moving all
around it becomes critical to know what decltype does and when.


