#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

using namespace std;


vector<int> makeBigVector() {
    vector<int> result(1024);
    for (int i = 0; i < 1024; i++) {
        result[i] = rand();

    }
    std::cout << std::addressof(result) << std::endl;
    return result;
};


int main() {

    vector<int> v = makeBigVector();
    std::cout << std::addressof(v) << std::endl;

    return 0;
}