#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

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
    }
};


int main() {
    std::pair<int, int> pp(10, 20);
//    pp.swap(10);
    std::pair<int, int> pp11 = std::make_pair(34, 45);

    int f = pp.first;
    int f2 = pp.second;
//    Solution e = Solution();
//    vector<int> e1{3, 4, 5};
//    e.nextPermutation(e1);
    return 0;
}