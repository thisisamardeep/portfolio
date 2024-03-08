#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

using namespace std;

class Foo {
public:
    Foo() {

    }

    Foo(int x) : mX{x} {

    }

public:
    int mX = 0;
};

void printFoo1(const Foo &foo) {
    std::cout << foo.mX << std::endl;

}

void printFoo2(const Foo foo) {
    std::cout << foo.mX << std::endl;
}

int main() {
    float f;
    auto i = static_cast<int>(f);
    return 0;
}