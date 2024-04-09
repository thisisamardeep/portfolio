

//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150




#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    void myrec(vector<int> &nums, int currindex, int &countofways) {
        if (currindex == nums.size() - 1) {
            countofways++;
            return;
        }
        if (currindex > nums.size() - 1) {
            return;
        }
        for (int i = 1; i <= nums[currindex]; i++) {
            myrec(nums, currindex + i, countofways);
        }
    }

public:
    bool canJump(vector<int> &nums) {
        int countofways = 0;
        myrec(nums, 0, countofways);
        if (countofways == 0) {
            return false;
        } else {
            return true;
        }
    }
};

int main() {
    Solution df{};
//    vector<int> nums{5, 2, 1, 0, 4};
    vector<int> nums{2, 3, 1, 1, 4};
//    vector<int> nums{2, 0, 0};

    bool res = df.canJump(nums);

    return 0;
}