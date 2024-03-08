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
    std::string str1 = "Hello";
    std::string str2 = " Underworld";
    std::string str3 = str1 + str2;
    std::string& str_lref = str3; // Cannot do lvalue reference std::string& str_lref = str1 + str2, because str1 + str2 is rvalue expression
//    std::string& str_lref1 = str1 + str2; // Cannot do lvalue reference std::string& str_lref = str1 + str2, because str1 + str2 is rvalue expression
    std::string&& str_rref = str1 + str2; // rvalue reference

    return 0;
}