#include <unordered_map>
#include "iostream"
#include <cassert>
#include "map"
#include "vector"

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int> &nums) {
        map<int, map<int, int>> result;
        if (result[6][56] > 8) {
            int ty = 67;
        }
//        result.insert(std::make_pair(23, map<int, int>{std::make_pair(34, 45)}));
        unsigned long max_length = 0;
//        for (int i = 1; i < nums.size(); i++) {
//            for (int j = 0; j < i; j++) {
//                int size_temp = nums[i] - nums[j];
//                if (result[j].count(size_temp) > 0) {
//                    if (result.count(i) > 0) {
//                        result[i][size_temp] = result[j][size_temp] + 1;
//
//                    } else {
//                        result[i] = map<int, int>{std::make_pair(size_temp, 2)};
//                    }
//                } else {
//                    if (result.count(i) > 0) {
//                        result[i][size_temp] = 2;
//                    } else {
//                        result[i] = map<int, int>{std::make_pair(size_temp, 2)};
//                    }
//                }
//
//
//            }
//        }
        return static_cast<int>(max_length);
    }
};

int main() {
    Solution *rr = new Solution{};
    vector<int> nums = {9, 4, 7, 2, 10};
    auto res = rr->longestArithSeqLength(nums);
    std::cout << res << std::endl;
    return 0;
}