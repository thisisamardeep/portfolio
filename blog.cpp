#include "set"
#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"

using namespace std;

class Solution {
public:
    void selectionsort(std::vector<int> &nums) {
        size_t counter_to_be_processed = 0;
        while (counter_to_be_processed < nums.size()) {
            for (size_t i = counter_to_be_processed; i < nums.size(); i++) {
                // swap elements of different indices
                if (nums[counter_to_be_processed] < nums[i]) {
                    std::swap(nums[i], nums[counter_to_be_processed]);
                }
            }
            counter_to_be_processed = counter_to_be_processed + 1;
        }
    };

    void bubblesort(std::vector<int> &nums) {

        for (size_t i = nums.size() - 1; i > 0; i = i - 1) {
            for (size_t j = 0; j < i; j++) {
                // swap adjeacent elements only so the bubble up
                if (nums[j] < nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    void insertsort(std::vector<int> &nums) {
        for (size_t i = 0; i < nums.size(); i = i + 1) {
            size_t j = i;
            while ((j > 0) && (nums[j] > nums[j - 1])) {
                swap(nums[j], nums[j - 1]);
                j = j - 1;
            }

        }
    }
};


int main() {
    int ty = 67;
    vector<int> inp = {7, 5, 9, 2, 8};


    Solution df{};
//    df.selectionsort(inp);
//    df.bubblesort(inp);
    df.insertsort(inp);
    return 0;
}