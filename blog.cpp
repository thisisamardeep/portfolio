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

    std::vector<int> mergme(std::vector<int> &nums, size_t start, size_t middle, size_t end) {
        size_t i = start;
        size_t j = middle + 1;
        std::vector<int> res{};
        while ((i <= middle) || (j <= end)) {
            if ((i <= middle) && (j <= end)) {
                if (nums[i] <= nums[j]) {
                    res.push_back(nums[i]);
                    i = i + 1;
                } else {
                    res.push_back(nums[j]);
                    j = j + 1;
                }
            } else if ((i <= middle) && (j > end)) {
                res.push_back(nums[i]);
                i = i + 1;
            } else if ((i > middle) && (j <= end)) {
                res.push_back(nums[j]);
                j = j + 1;
            }
        }
        return res;
    }


    void mergrec(std::vector<int> &nums, size_t start, size_t end) {
        if (start == end) {
            return;
        }
        size_t middle = (start + end) / 2;
        mergrec(nums, start, middle);
        mergrec(nums, middle + 1, end);
        std::vector<int> temp1 = mergme(nums, start, middle, end);
        size_t c = start;
        while (c <= end) {
            nums[c] = temp1[c - start];
            c = c + 1;
        }
    }
    std::vector<int> sortArray(std::vector<int> &nums) {
        mergrec(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main() {
    int ty = 67;
    vector<int> nums = {7, 5, 9, 2};
    vector<int> nums11{};
//    nums11=nums(nums.begin(),nums.end());

//    std::cout << 5 / 2 << std::endl;
//    std::cout << -5 / 2 << std::endl;


    Solution df{};
////    df.selectionsort(inp);
////    df.bubblesort(inp);
////    df.insertsort(inp);
    df.mergesort(nums);
    return 0;
}