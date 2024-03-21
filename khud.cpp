

//https://leetcode.com/pr131oblems/median-of-two-sorted-arrays/description/?envType=featured-list&envId=top-100-liked-questions?envType=featured-list&envId=top-100-liked-questions






#include "iostream"
#include "vector"
#include "stack"

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        std::stack<int> t1{};
        int counter_1{0};
        int counter_2{0};

        while (counter_1 < nums1.size() || counter_2 < nums2.size()) {
            if (counter_1 < nums1.size() && counter_2 < nums2.size()) {
                if (nums1[counter_1] <= nums2[counter_2]) {
                    t1.push(nums1[counter_1]);
                    counter_1++;
                } else {
                    t1.push(nums2[counter_2]);
                    counter_2++;

                }

            } else if (counter_1 < nums1.size() && counter_2 >= nums2.size()) {
                t1.push(nums1[counter_1]);
                counter_1++;
            } else if (counter_1 >= nums1.size() && counter_2 < nums2.size()) {
                t1.push(nums2[counter_2]);
                counter_2++;
            }


        }
        int ty = 67;
        return 0;


    };
};


int main() {


    vector<int> nums1{1, 3, 5};
    vector<int> nums2{2};


    Solution s{};
    auto res = s.findMedianSortedArrays(nums1, nums2);
    return 0;
}