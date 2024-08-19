#include <functional>
#include "iostream"
#include "thread"
#include "vector"
#include "queue"
#include "string"

using namespace std;

#include "iostream"
#include "queue"
#include "string"
#include "thread"
#include "vector"
#include <functional>

using namespace std;

class Solution {
public:
    string betterCompression(const string &compressed) {


        return "34";
    }
};
//    Solution rr{};
//    auto res = rr.betterCompression("a3c9b2c1");
//    std::cout << res << std::endl;
/**
 *
 *
 * stl concepts needed.get substring in c++
 * check if string is alpahet or number both via char or via string
 * add in map
 * update in map
 * sort keys in map for both types of maps
 * @return
 */
int main() {


    std::string mystring{"35ddfhefss"};
    // This will start at index pos and end till end of String
    auto newString = mystring.substr(2);
    std::cout << newString << std::endl;
    // This will go for 3 more digits.So new string will have size 3
    auto newStringOverload = mystring.substr(2,3);
    std::cout << newStringOverload << std::endl;
    return 0;
}