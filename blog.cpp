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
    string minRemoveToMakeValid(const string &s) {
        std::string s1{""};
        int count_excess_left = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count_excess_left = count_excess_left + 1;
                s1 = s1 + s[i];
            } else if (s[i] == ')') {
                if (count_excess_left == 0) {
                } else {
                    s1 = s1 + s[i];
                    count_excess_left = count_excess_left - 1;
                }
            } else {
                s1 = s1 + s[i];
            }
        }

        std::string s2{""};
        int count_excess_right = 0;

        for (int i = s1.length() - 1; i >= 0; i--) {
            if (s1[i] == ')') {
                count_excess_right = count_excess_right + 1;
                s2 = s1[i] + s2;
            } else if (s1[i] == '(') {
                if (count_excess_right == 0) {
                } else {
                    s2 = s1[i] + s2;
                    count_excess_right = count_excess_right - 1;
                }
            } else {
                s2 = s1[i] + s2;
            }
        }
        return s2;
    }
};


int main() {
    Solution rr{};
    auto res = rr.minRemoveToMakeValid("lee(t(c)o)de)");
    std::cout << res << std::endl;

    return 0;
}