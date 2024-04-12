

//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150




#include <unordered_map>
#include "iostream"
#include <cassert>
#include "map"

using namespace std;

int main() {
//    std::unordered_map<int, std::string> m;
    std::map<int, std::string> m;
    m[1] = "ee";
    m.insert(std::make_pair(23, "ee"));
    m.insert(std::pair(34, "333"));
    m.insert({2, "err"});
//    for (auto i: m) {
//        std::cout << i.first << std::endl;
//
//
//        assert((is_same<decltype(i), pair<const int, string>>::value));
//        assert((is_same<decltype(i.first), const int>::value));
//        assert((is_same<remove_const<remove_reference<decltype(i.first)>::type>::type, int>::value));
//        assert((is_same<decltype(i.second), string>::value));
//
//
//    }

    for (auto i = m.begin(); i != m.end(); i++) {
        std::cout << i->first << std::endl;


    }

    return 0;
}