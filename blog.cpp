#include "set"
#include "iostream"
#include "vector"


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