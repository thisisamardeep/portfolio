#include "iostream"
#include "memory"
#include "thread"
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0) {
            return;
        }
        if (m == 0) {
            return;
        }

        int insert_counter = m + n - 1;
        int second_vector_counter = n - 1;
        int first_vector_counter = m - 1;
        // this can be negative and can go till -n
        while (insert_counter >= 0) {
            if (first_vector_counter >= 0 &&
                nums1[first_vector_counter] > nums2[second_vector_counter]) {
                nums1[insert_counter] = nums1[first_vector_counter];
                insert_counter = insert_counter - 1;
                first_vector_counter = first_vector_counter - 1;
            } else {
                nums1[insert_counter] = nums2[second_vector_counter];
                insert_counter = insert_counter - 1;
                second_vector_counter = second_vector_counter - 1;
            }
        }
    }
};

int main() {
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{2, 5, 6};
    Solution e{};
    e.merge(nums1, 3, nums2, 3);
    return 0;
};