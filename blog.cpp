//#include "set"

#include "iostream"
#include "vector"
#include "cassert"
#include "stack"
//https://leetcode.com/problems/longest-arithmetic-subsequence/description/

//write blog about how the dp works
// do in via hashmap
// do it in python


using namespace std;


class Solution {

public:
    void amar(vector<int> &nums, int curr_index,
              vector<vector<int>> &finalresult, vector<int> &partial, size_t &max_size) {
        std::cout << max_size << std::endl;
        std::cout << curr_index << std::endl;
        if (curr_index >= nums.size()) {
            return;
        }
        amar(nums, curr_index + 1, finalresult, partial, max_size);
        partial.push_back(nums[curr_index]);
        if (partial.size() > 2 && checkarithmetic(partial)) {
            max_size = max(max_size, partial.size());

        }
        amar(nums, curr_index + 1, finalresult, partial, max_size);
        partial.pop_back();
    }

public:
    bool checkarithmetic(const vector<int> &temp) {
        if (temp.size() == 2) {
            return true;
        }
        int t = temp[1] - temp[0];
        for (int i = 1; i < temp.size() - 1; i++) {
            if (temp[i + 1] - temp[i] == t) {

            } else {
                return false;
            }
        }
        return true;
    }

public:
    int longestArithSeqLength(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        if (nums.size() == 2) {
            return 2;
        }
        vector<vector<int>> finalresult{};
        vector<int> partial{};

        size_t max_size = 0;

        amar(nums, 0, finalresult, partial, max_size);

        return max_size;
    }
};

int main() {

//    std::vector<int> nums = {12, 28, 13, 6, 34, 36, 53, 24, 29, 2, 23, 0, 22, 25, 53, 34, 23, 50, 35, 43, 53, 11, 48, 56, 44, 53, 31, 6, 31, 57, 46, 6, 17, 42, 48, 28, 5, 24, 0, 14, 43, 12, 21, 6, 30, 37, 16, 56, 19, 45, 51, 10, 22, 38, 39, 23, 8, 29, 60, 18};
    std::vector<int> nums = {6, 31, 57, 8, 39, 23, 8, 29, 60, 18};

    Solution er{};

    int res = er.longestArithSeqLength(nums);
    return 0;
}