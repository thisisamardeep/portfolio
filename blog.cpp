#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"


//using namespace std;
//
//decltype(auto) f() {
//    static int i = 0;
//    std::cout << i << std::endl;
//    return (i);
//}

class Foo {

};

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