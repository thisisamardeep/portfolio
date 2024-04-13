


#include <unordered_map>
#include "iostream"
#include <cassert>
#include "map"
#include "vector"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int majElement = 0;
        int majElementCount = 0;
        map<int, int> mymap{};
        for (int i = 0; i < nums.size(); i++) {
            if (mymap.count(nums[i]) == 0) {
                mymap[nums[i]] = 1;
            } else {
                mymap[nums[i]] = mymap[nums[i]] + 1;
                if (majElementCount < mymap[nums[i]]) {
                    majElementCount = mymap[nums[i]];
                    majElement = nums[i];
                }
            }
        }
        return majElement;
    }
};

int main() {
    Solution *rr = new Solution{};
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    rr->majorityElement(nums);


    return 0;
}