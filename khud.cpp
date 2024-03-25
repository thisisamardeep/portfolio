

//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150




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
        int counter_full{0};
        int break_point = (nums1.size() + nums2.size()) / 2;

        while (counter_1 < nums1.size() || counter_2 < nums2.size()) {
            if (counter_1 < nums1.size() && counter_2 < nums2.size()) {
                if (nums1[counter_1] <= nums2[counter_2]) {
                    t1.push(nums1[counter_1]);
                    counter_1++;
                    counter_full++;
                } else {
                    t1.push(nums2[counter_2]);
                    counter_2++;
                    counter_full++;
                }

            } else if (counter_1 < nums1.size() && counter_2 >= nums2.size()) {
                t1.push(nums1[counter_1]);
                counter_1++;
                counter_full++;

            } else if (counter_1 >= nums1.size() && counter_2 < nums2.size()) {
                t1.push(nums2[counter_2]);
                counter_2++;
                counter_full++;

            }
            if (counter_full - 1 == break_point) {
                break;
            }
        }

        if ((nums2.size() + nums1.size()) % 2 == 0) {
            double t41 = t1.top();
            t1.pop();
            double t42 = t1.top();
            return (t41 + t42) / 2;

        } else {
            double t4 = t1.top();
            return t4;
        }
//        return 0;


    };
};


int main() {


    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};


    Solution s{};
    auto res = s.findMedianSortedArrays(nums1, nums2);
    return 0;
}