//#include "set"

#include "iostream"
#include "vector"
#include "cassert"
#include "stack"
//https://leetcode.com/problems/longest-arithmetic-subsequence/description/

//write blog about how the dp works
// do in via hashmap
// do it in python


class Foo {

};

int main() {

    int i = 67;
    static_assert((std::is_same_v<decltype(i), int>));
    static_assert((std::is_same_v<decltype((i)), int &>));

    Foo obj{};
    static_assert((std::is_same_v<decltype(obj), Foo>));
    static_assert((std::is_same_v<decltype((obj)), Foo &>));

    return 0;
}