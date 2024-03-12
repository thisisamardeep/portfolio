#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int count_zeros = 0;
        int count_ones = 0;
        int count_twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count_zeros = count_zeros + 1;
            } else if (nums[i] == 1) {
                count_ones = count_ones + 1;
            } else if (nums[i] == 2) {
                count_twos = count_twos + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < count_zeros) {
                nums[i] = 0;
            } else if (i >= count_zeros && i < count_ones + count_zeros) {
                nums[i] = 1;
            } else if (i >= count_ones && i < nums.size()) {
                nums[i] = 2;
            }
        }

    }
};


int main() {
    Solution df{};
    vector<int> ee{2, 0, 2, 1, 1, 0};
    df.sortColors(ee);


    return 0;
}