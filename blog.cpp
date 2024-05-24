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

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int curr_start = 0;
        int curr_end = 0;
        int jumps = 0;
        while (true) {
            if (curr_end == nums.size() - 1) {
                break;
            }
            int new_end = 0;
            int new_start = 0;
            for (int i = curr_start; i <= curr_end; i++) {
                new_end = max(new_end, i + nums[i]);
            }
            new_end = min(new_end, static_cast<int>(nums.size() - 1));
            new_start = min(curr_end + 1, static_cast<int>(nums.size() - 1));
            curr_start = new_start;
            curr_end = new_end;
            jumps = jumps + 1;
        }
        return jumps;
    }
};

int main() {

    vector<int> nums{2, 3, 1, 1, 4};
    Solution *s = new Solution{};
    int curr = 0;
    vector<int> partial{};
    int res = s->jump(nums);
    return 0;
}