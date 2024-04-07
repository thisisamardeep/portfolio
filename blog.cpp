#include "set"
#include "iostream"
#include "vector"


class Foo {

};

int &TestFun() {
    static int i = 0;
    std::cout << i << std::endl;
    return i;
}

template<typename T>
auto TemplTestFun(T a) -> decltype(auto) {
    static T i = 0;
    std::cout << i << std::endl;
    return (i);
}

int main() {

    TemplTestFun(2);
    TemplTestFun(2)++;
    TemplTestFun(2);

    TemplTestFun(2.4);
    TemplTestFun(2.4)++;
    TemplTestFun(2.4);

    return 0;
}