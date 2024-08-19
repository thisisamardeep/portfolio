---
title: maps in c++
published: true
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/string-in-cpp"
share-description: "string in c++"
comments: false
---


How to loop over a string.
We can loop over a string and each element is of type char.
```cpp

int main() {
    std::string mystring{"35ddf"};
    for (int i = 0; i < mystring.size(); i++) {
        // access element of String
        std::cout << mystring.at(i) << std::endl;
        // access element of String
        std::cout << mystring[i] << std::endl;
    }
    // Get last character of String
    std::cout << mystring.back() << std::endl;
    // Get First character of String
    std::cout << mystring.front() << std::endl;
//Front element is the element at index 0.
    return 0;
}
```

c++ substring has 2 overloaded functions substr.
substring returns a new string.

```cpp

int main() {


std::string mystring{"35ddfhefss"};
// This will start at index pos and end till end of String
auto newString = mystring.substr(2);
std::cout << newString << std::endl;
// This will go for 3 more digits.So new string will have size 3
auto newStringOverload = mystring.substr(2,3);
std::cout << newStringOverload << std::endl;
return 0;
}
```
c++ string how to check if a charaxcter is digit.
int res=std::isdigit(<<char>>)

if it is yes then res !=0 else res is 0.
So for all false cases res is 0.
for all true cases res is non zero.

```cpp

int main() {

   
    std::string mystring{"35ddfhefss"};
    int result =std::isdigit(mystring.at(2));
    // result will be 0
    int result =std::isdigit(mystring.at(0));
    // result will be non zero
    if (result == 0){
        std::cout << result << std::endl;
    }
    return 0;
}

```