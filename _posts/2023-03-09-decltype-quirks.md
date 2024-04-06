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
in libraries since we need to know how compiler is decuding the return types.
Consider a integer variable and let us try to use decltype on it.

(i) is a expression. So it is treated differently and we get a reference to int.

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

decltype(auto) can be used to perfect forward a return value.
In template code or for that matter in any code our ability or non ability to return a reference 
makes all the difference.

Consider the below example.We have a function and it has a static variable.We  need to be 
able to return the static variable since we know we will be incrementing it.
