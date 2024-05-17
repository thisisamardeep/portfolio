//#include "set"

#include "iostream"
#include "vector"
#include "cassert"
#include "stack"
//https://leetcode.com/problems/longest-arithmetic-subsequence/description/

//write blog about how the dp works
// do in via hashmap
// do it in python


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