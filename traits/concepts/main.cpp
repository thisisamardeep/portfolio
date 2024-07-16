//
// Created by amardeep on 15/07/24.
//
#include "iostream"


template<typename T>
typename std::enable_if<(sizeof(T) > 4), void>::type foo(T y) {
//    T rt;
//    return rt;
}
//
template<>
void foo(float r) {

}

int main() {
    std::cout << sizeof(float) << std::endl;
//    foo(3.5);
//    foo(3);
    unsigned long long dd=56;
    foo(dd);
//    auto foo(45);

    return 0;
};