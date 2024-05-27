//#include "set"

#include "iostream"
#include "vector"
#include "cassert"
#include "stack"
//https://leetcode.com/problems/longest-arithmetic-subsequence/description/

//write blog about how the dp works
// do in via hashmap
// do it in python

#include "vector"
#include "map"
#include "string"
using namespace std;

class Solution {
public:

    void amar(int &n, int left_used, int right_used, std::string &partial, vector<string> &result) {
        if (left_used > n || right_used > n) {
            return;
        }
        if (left_used == n && right_used == n) {
            result.push_back(partial);
            return;
        }
        if (left_used > right_used) {
            partial.append("(");
            amar(n, left_used + 1, right_used, partial, result);
            partial.pop_back();
            partial.append(")");
            amar(n, left_used, right_used + 1, partial, result);
            partial.pop_back();

        } else if (left_used == right_used) {
            partial.append("(");
            amar(n, left_used + 1, right_used, partial, result);
            partial.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {

        std::string partial = "(";
        vector<string> result{};
        amar(n, 1, 0, partial, result);
        return result;

    }
};

int main() {
//    std::string partial = "(";
//    partial.append("df");
//    partial.pop_back();
//    std::cout << partial << std::endl;
    int n = 3;
    Solution *s = new Solution{};
    vector<string> res = s->generateParenthesis(n);
    return 0;
}