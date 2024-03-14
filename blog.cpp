#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {

        int max_index_zero = -1;
        int max_index_one = -1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                max_index_zero = i;
            } else if (nums[i] == 1) {
                max_index_one = i;
            } else if (nums[i] == 2) {

            }


            if (nums[i] > nums[i + 1]) {

                // there are 3  conditions 1 0   2 0   2 1
                if (nums[i] == 1 && nums[i + 1] == 0) {
                    // 1 0
                    swap(nums[i], nums[i + 1]);
                    max_index_zero = max_index_zero + 1;
                } else if (nums[i] == 2 && nums[i + 1] == 1) {
                    // 2 1
                    swap(nums[i], nums[i + 1]);
                    max_index_one = i;
                } else if (nums[i] == 2 && nums[i + 1] == 0) {
                    // 2 0
                    if (max_index_one == -1) {
                        swap(nums[i], nums[i + 1]);
                        max_index_one = i;
                    } else {
                        nums[max_index_zero + 1] = 0;
                        max_index_zero = max_index_zero + 1;
                        nums[max_index_one + 1] = 1;
                        max_index_one = max_index_one + 1;
                        nums[i + 1] = 2;
                    }


                }


            } else {

            }
        }

    }
};


int main() {
    int rt = 56;
    float rt1 = 34.566;
    std::cout << sizeof(rt) << std::endl;
    std::cout << sizeof(rt1) << std::endl;
    return 0;
}