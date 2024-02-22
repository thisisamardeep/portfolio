
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int idx = -1;
        for (int i = nums.size() - 2; i >= 0; i++) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            // edge case
            reverse(nums.begin(), nums.end());
            return;

        } else {
            // need to handle the normal case
            int rightidx = -1;
            //Now we start from right and find rightidx such that number at idx is less than number at rightidx
            for (int j = nums.size() - 1; j > idx; j--) {
                if (nums[idx] < nums[j]) {
                    rightidx = j;
                    break;
                }
            }
            if (rightidx == -1) {
                // this will never be the case
            } else {
                swap(nums[idx], nums[rightidx]);
                reverse(nums.begin() + idx + 1, nums.end());
                return;
            }
        }
    }
};

int main() {
    vector<int> input = {1, 2, 3, 4};
    Solution s{};
    s.nextPermutation(input);
    return 0;
}
