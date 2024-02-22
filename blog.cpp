
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
            reverse(nums.begin(),nums.end());
            return;

        } else {
            // need to handle the normal case
        }
    }
};

int main() {
    vector<int> input = {1, 2, 3, 4};
    Solution s{};
    s.nextPermutation(input);
    return 0;
}
