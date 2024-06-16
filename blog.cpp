#include "iostream"
#include "vector"
#include <random>

using namespace std;

class Customer {
private:
    std::string name;
    std::vector<int> values;
public:
    Customer(const std::string &n) : name{n} {

    }

    std::string getName() const {
        return name;
    }

    void addValue(int val) {
        values.push_back(val);
    }
};

Customer createCustomer() {
    // initialize random-number generator for values from 0 to 999:
    static std::default_random_engine rndEngine;
    static std::uniform_int_distribution<int> distr{0, 999};

    // create customers with unique name and 10 random values:
    static int no{0};
    Customer c{"my test customer " + std::to_string(++no)};
    for (int i = 0; i < 1; ++i) {
        c.addValue(distr(rndEngine));
    }
    return c;  // uses move semantics if not optimized away
}


int main() {
    Customer c{"Wolfgang Amadeus Mozart"};
    for (int val: {0, 8, 15}) {
        c.addValue(val);
    }
    std::vector<Customer> customers;
    customers.push_back(createCustomer());
//    customers.push_back(std::move(c));
    return 0;
};