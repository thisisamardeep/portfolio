

//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150




#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    void myrec(vector<int> &nums, int currindex, int &countofways, vector<vector<int>> &finalres, vector<int> &temp) {
        if (currindex == nums.size() - 1) {
            finalres.push_back(temp);
            countofways++;
            return;
        }
        if (currindex > nums.size() - 1) {
            return;
        }


        for (int i = 1; i <= nums[currindex]; i++) {
            temp.push_back(currindex + i);
            myrec(nums, currindex + i, countofways, finalres, temp);
            temp.pop_back();

        }

    }

public:
    bool canJump(vector<int> &nums) {
        vector<vector<int>> finalres{};
        vector<int> temp{};
        temp.push_back(0);
        int countofways = 0;
        myrec(nums, 0, countofways, finalres, temp);
        std::cout << countofways << std::endl;
        if (countofways == 0) {
            return false;
        } else {
            return true;
        }
    }
};

int main() {
    Solution df{};
    vector<int> nums{2, 3, 1, 1, 4};
//    vector<int> nums{8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7,
//                     6, 5, 1, 7, 0, 3, 4, 8, 3, 5, 9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2, 3, 9, 7,
//                     4, 7, 0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5};
//    vector<int> nums{2, 0, 0};

    bool res = df.canJump(nums);

    return 0;
}