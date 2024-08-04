#include <functional>
#include "iostream"
#include "thread"
#include "vector"

class Base {
public:
    virtual void someFunction() {

    }
};

class Derived : public Base {
public:
    using Base::someFunction;
    virtual void someFunction(int i){

    }

};

int main() {


    std::cout << 56 << std::endl;
    return 0;
};
/***
*
 *
 *
 *
 *
 *
*/