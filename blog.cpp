#include <functional>
#include "iostream"
#include "thread"
#include "vector"
#include "set"
#include "mutex"


class X {

};

void foo(const X &) {

}

//void foo(X) {
//
//}

void foo(X &) {

}

void foo(X &&) {

}

int main() {
    X v;
    const X c;
    foo(v);
    foo(c);
    foo(X{});

    return 0;
};