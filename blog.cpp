#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"
#include "cassert"

using namespace std;

decltype(auto) f() {
    static int i = 0;
    std::cout << i << std::endl;
    return (i);
}

int main() {
//    int tt = 56;
//    float tt211 = 56.45;
//
//    decltype(auto) eee = rr();
//    f()++;
//    f()++;
//    f();
    int ty = 67;
//    rrr = 444;
//    std::cout << rrr << std::endl;

//    std::cout << std::is_same<decltype(tt), decltype(tt211)>::value << std::endl;
//    std::cout << std::is_same_v<decltype(tt), decltype(tt211)> << std::endl;
    std::cout << std::is_same_v<decltype((ty)), int &> << std::endl;
//    assert(std::is_same_v<decltype((ty)), int &>);
    assert((std::is_same_v<decltype(ty), int>));      // OK: one argument
    assert((std::is_same_v<decltype((ty)), int &>));      // OK: one argument

    std::cout << std::is_same_v<decltype(ty), int> << std::endl;
//    static_assert(std::is_same_v<decltype(ty), int &>);

    return 0;
}