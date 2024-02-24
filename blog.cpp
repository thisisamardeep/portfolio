


class Base {
public:
    virtual void someMethod() {}

protected:
    int m_protectectInt{0};
private:
    int m_privateINT{0};
};


class Derived : public Base {
public:
    void someother() {};

    void someMethod() override {

    }
};

int main() {
    Derived e;
    e.someother();
    e.someMethod();
    Base r;
//    r.

    return 0;
}
