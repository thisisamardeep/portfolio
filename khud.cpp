

//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150




#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }

        int curr = 0;
        while (curr <= nums.size() - 1) {

            if (nums[curr] == 0) {
                bool canpass = false;

                for (int i = 0; i < curr; i++) {
                    if (nums[i] > curr - i) {
                        canpass = true;
                        break;
                    } else if ((nums[i] = curr - i) && (curr == nums.size() - 1)) {

                    }

                }

                if (!canpass) {
                    break;
                } else {
                    curr++;
                }

            } else {
                curr++;
            }
        }

        if (curr == nums.size()) {
            return true;
        } else {
            return false;
        }


    }
};

int main() {
    Solution df{};
//    vector<int> nums{2, 3, 1, 1, 4};
    vector<int> nums{2, 0, 0};

    bool res = df.canJump(nums);

    return 0;
}