//
// Created by amardeep on 18/02/24.
//
// C++ Program to print all permutations
// of a string in sorted order.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() == 1)
            return;
        set<pair<int, int>> s;
        bool found = false;
        s.insert({nums[nums.size() - 1], nums.size() - 1});
        for (int i = nums.size() - 2; i >= 0; i--) {
            int current_no = nums[i];
            pair<int, int> z = {INT_MAX, INT_MAX};
            bool flag = false;
            for (auto it: s) {
                if (it.first > current_no) {
                    flag = true;
                    z = min(z, it);
                }
            }
            if (flag) {
                found = true;
                s.erase(z);
                s.insert({current_no, i});
                nums[i] = z.first;
                int j = i + 1;
                for (auto it: s) {
                    nums[j] = it.first;
                    j++;
                }
                break;
            }
            s.insert({nums[i], i});
        }
        if (!found) {
            return sort(nums.begin(), nums.end());
        }
        //stl provided by c++ next_permutation(nums.begin(),nums.end());

    }
};

int main() {
    vector<int> rr = {1, 2, 3};
    Solution r{};
    r.nextPermutation(rr);
    return 0;
}

// This is code is contributed by rathbhupendra
