#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

using namespace std;


class Solution {
public:
    void
    amarec(vector<int> &nums, size_t index_first, size_t index_second, size_t index_third, vector<vector<int>> &result
    ) {

        if (index_third > nums.size() - 1) {
            return;
        }
        if (index_second > nums.size() - 2) {
            return;
        }
        if (index_first > nums.size() - 3) {
            return;
        }

        if (index_third == nums.size() - 1) {
            if (index_second == nums.size() - 2) {
                amarec(nums, index_first + 1, index_first + 2, index_first + 3, result);
            } else {
                amarec(nums, index_first, index_second + 1, index_second + 2, result);
            }

        } else if (index_third < nums.size() - 1) {
            amarec(nums, index_first, index_second, index_third + 1, result);
        }


        if (0 == nums[index_first] + nums[index_second] + nums[index_third]) {
            vector<int> temp{nums[index_first], nums[index_second], nums[index_third]};
            sort(temp.begin(), temp.end());
            bool found = false;
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == temp) {
                    found = true;
                    break;
                }

            }
            if (!found) {
                result.push_back(temp);
            }


        }


    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result{};
        amarec(nums, 0, 1, 2, result);
        return result;
    };
};


int main() {
    Solution df{};
    vector<int> ee{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> resul1t{};
    resul1t = df.threeSum(ee);


    return 0;
}