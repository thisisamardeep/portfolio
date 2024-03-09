#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

using namespace std;


class Foo {
    int test;
    float test_float;

    explicit operator float() const {
        return test;
    }
//    explicit operator float () const {
//        return test_float;
//    }
};

int main() {
    float f;
    auto i = static_cast<int>(f);
    std::cout << f << std::endl;
    return 0;
}