

//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150




#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        bool res = true;
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (reachable < i) {
                res = false;
                break;
            } else {
                reachable = max(reachable, i + nums[i]);
            };
        }
        return res;
    }
};

int main() {
    Solution df{};
    vector<int> nums{3, 2, 1, 0, 4};
//    vector<int> nums{2, 0, 0};

    bool res = df.canJump(nums);

    return 0;
}