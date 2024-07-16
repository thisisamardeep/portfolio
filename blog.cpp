#include <functional>
#include "iostream"
#include "thread"
#include "vector"
#include "set"
#include "mutex"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            } else {
                return 1;
            }
        }

        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;
        while (low < high) {
            mid = (low + high) / 2;
            if ((low == 0) && (nums[low] > nums[low + 1])) {
                return low;
            }
            if ((high == nums.size() - 1) && (nums[high] > nums[high - 1])) {
                return high;
            }
            if (nums[mid] > nums[mid + 1] && nums[mid - 1] < nums[mid]) {
                return mid;
            }

            if ((nums[mid - 1] < nums[mid]) && (nums[mid] < nums[mid + 1])) {
                low = mid;
            } else if ((nums[mid - 1] > nums[mid]) &&
                       (nums[mid] > nums[mid + 1])) {
                high = mid;
            } else {
                low = mid;
            }


        }
        return 0;
    }
};


int main() {
    vector<int> rtt{1, 2, 1, 2, 1};

    Solution r{};
    auto deree = r.findPeakElement(rtt);
    return 0;
};
/***
*
 *
 *
 *
 *
 *
*/