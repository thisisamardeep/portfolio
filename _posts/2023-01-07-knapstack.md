---
title: Vexing Parse Cause and Scenarios
published: true
share-description: ""
tags: [ c++ ]
share-img: /img/rust.png
readtime: true
permalink: "/0-1-vexing-parse"
share-description: "Vexing Parse"
comments: false
---

First Let me share the [wiki](https://en.wikipedia.org/wiki/Most_vexing_parse) and the [cpp reference](https://en.cppreference.com/w/cpp/language/direct_initialization)  (see notes section) 
which mentions this problem.

The Official Explanation :
In case of ambiguity between a variable declaration using the direct-initialization syntax (1) (with round parentheses) and a function declaration, the compiler always chooses function declaration. This disambiguation rule is sometimes counter-intuitive and has been called the most vexing parse.


Suppose we have a class foo. There are three ways post C++11 to create object of class foo

 foo obj;

 foo obj();  --> This is the cause of the ambiguity.

 foo obj{};

Function Declaration
A function declaration just introduces the function name and its type and some other optional specifiers.The Compiler will call the function
referencing a yet undefined symbol.
The Linker gets the transalation units and resolves the mangled symbols by name.There can be multiple declarations of the same function but there should
be one definition only.
First Approach:
