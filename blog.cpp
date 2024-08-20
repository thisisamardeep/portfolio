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
#include "map"

using namespace std;

#include "string"

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
    std::unordered_map<int, std::string> m;
    m[1] = "ee"; // first way
    m.insert(std::make_pair(23, "ee"));// second way
    m.insert(std::pair(34, "333")); // third way
    m.insert({2, "err"});  //fourth way

    for (std::pair<int, std::string> item: m) {
        std::cout << item.first << std::endl;
    }
    return 0;
}