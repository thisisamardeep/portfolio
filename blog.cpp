//#include "set"
#include "iostream"


class Base1 {
public:
    Base1() {
        std::cout << "Base ctor" << std::endl;
    }

    virtual ~Base1() {
        std::cout << "Base dtor" << std::endl;

    }

    void v1() {

    }

    void v2() {

    }


};

class Derived1 : public Base1{
public:
    Derived1() {
        std::cout << "Derived ctor" << std::endl;
    }

    void v1() {

    }

    virtual void v2() {

    }

    ~Derived1() override {
        std::cout << "Derived dtor" << std::endl;

    }


};


int main() {
    Base1 *b = new Derived1();
    Base1 *b1 = new Derived1();
    Base1 *b11111 = new Derived1();
    Base1 *b3 = new Derived1();
    Base1 *bw = new Base1();
    delete b;

//    e1->f1();
//    e1->f2();
//    e1.f2();


////    Parent p1{};
//    Parent *p1 = new Parent{};
//    p1 = e1;
////    Parent &p1 = e1;
//    p1->f1();
////    p1->f2();

//    Parent p2{};
//    p2.f2();
//    p2.f1();
//    p2.f222();

    //    Amar ee33{};
//    Amar ewewee{};
//    Amar ew2ewee{};
//    Amar ew4ewee{};
//    Amar ewrewee{};
//    Amar ew33ewee{};

//    std::cout << std::addressof(ee.ddddd)<< std::endl;
//    std::cout << sizeof(ee) << std::endl;
//    std::cout << &e1 << std::endl;
//    std::cout << &e2 << std::endl;
//    std::cout << &e3 << std::endl;
//    std::cout << &e1 - &e2 << std::endl;
//    std::cout << &e2 - &e3 << std::endl;
//    printf("Adr: 0x%08X\n", getaddr(&Amar::ddddd));

//    std::cout << &ee33 << std::endl;
//    std::cout << &ewewee << std::endl;
//    std::cout << &ew2ewee << std::endl;
//    std::cout << &ew4ewee << std::endl;
//    std::cout << &ewrewee << std::endl;
//    std::cout << &ew33ewee << std::endl;


    return 0;
}