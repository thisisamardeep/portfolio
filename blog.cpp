#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

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

    friend std::ostream &operator<<(std::ostream &strm, const Customer &cust) {
        strm << ' [ ' << cust.name << ": ";
        for (int val: cust.values) {
            strm << val << ' ';
        }
        strm << ' ] ';
        return strm;
    }

};


int main() {
    Customer c{"ttt ttt yutrrf erwwv wf23f e3tdx"};
    for (int val: std::initializer_list<int>{0, 8, 15}) {
        std::cout << val << std::endl;
        c.addValue(val);
    }
    std::cout << std::addressof(c) << std::endl;

    std::vector<Customer> customers;
//    customers.push_back(c);
        customers.push_back(std::move(c)); // move into the vector

    std::cout << c.getName() << std::endl;
    std::cout << std::addressof(customers[0]) << std::endl;

//    std::cout << std::addressof(customers[0].) << std::endl;

//    customers.push_back(std::move(c)); // move into the vector
//    std::cout << "customers:\n";
//    for (const Customer &cust: customers) {
//        std::cout << " " << std::addressof(cust) << ' \n ';
//    }
    return 0;
};