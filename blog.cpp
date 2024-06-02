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
#include "set"

using namespace std;

// write code just to return all possible subsets of the string porivided.
using namespace std;

// kk
class Solution {
public:
    void amar(string &s, set<string> &result_set, size_t curr_index, string &partial, size_t curr_left, size_t curr_right, size_t &curr_max_size) {
        if (curr_index > s.size()) {
            return;
        }
        if (curr_right > curr_left) {
            return;
        };

        if (curr_index <= s.size() && curr_left == curr_right) {

            if (partial.size() > curr_max_size) {
                result_set.clear();
                result_set.insert(partial);
                curr_max_size = partial.size();
            } else if (partial.size() == curr_max_size) {
                result_set.insert(partial);
            }

        }

        if (curr_index == s.size()) {
            return;
        }

        if (s[curr_index] == '(') {
            partial.insert(partial.size(), 1, s[curr_index]);
            amar(s, result_set, curr_index + 1, partial, curr_left + 1, curr_right, curr_max_size);
            partial.pop_back();
            amar(s, result_set, curr_index + 1, partial, curr_left, curr_right, curr_max_size);


        } else if (s[curr_index] == ')') {
            partial.insert(partial.size(), 1, s[curr_index]);
            amar(s, result_set, curr_index + 1, partial, curr_left, curr_right + 1, curr_max_size);
            partial.pop_back();
            amar(s, result_set, curr_index + 1, partial, curr_left, curr_right, curr_max_size);

        } else {
            partial.insert(partial.size(), 1, s[curr_index]);
            amar(s, result_set, curr_index + 1, partial, curr_left, curr_right, curr_max_size);
            partial.pop_back();

        }
    }

    vector<string> removeInvalidParentheses(string s) {
        string partial;
        vector<string> result_vector{};
        set<string> result_set;//we need to fill this
        int curr_left = 0;
        int curr_right = 0;
        size_t curr_max_size = 0;
        amar(s, result_set, 0, partial, curr_left, curr_right, curr_max_size);
        for (auto f: result_set) {
            result_vector.push_back(f);
        }
        return result_vector;
    }
};

int main() {
    Solution *s = new Solution{};
    string input = "(()";
    vector<string> res = s->removeInvalidParentheses(input);
    std::cout << 233 << std::endl;

    return 0;
};