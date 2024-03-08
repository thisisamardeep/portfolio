---
title: Static cast does not know at compile time
published: true
tags: [ c++ ]
readtime: true
permalink: "/static-cast-does-not--know-at-compile-time"
share-description: Static cast 
comments: false
---


"static" keyword has many meanings in the context of c++ compiler.You can mark a

variable as private, function call spanning,per call data.Just because static_cast 

has the word static many times we assume that it knows at compile time what is going 

to happen at run time .First static keyword has no relation with static_cast.

Every expression in c++ has 2 independent attributes.. type of the expression and 

its value category.(lvalue,rvalue,prvalue,glvalue,xvalue). static_cast(if successful) 

always changes  the type of the expression and gives a new expression which has the 

new type.But it may or may not change the value type of the expression. This is clear

for the standard [static _cast](https://en.cppreference.com/w/cpp/language/static_cast) .

So if we use static cast we need to also take into account the value category of the input 

and output expression.



