#include <functional>
#include "iostream"
#include "thread"
#include "vector"
#include "set"
#include "mutex"
#include "queue"
#include "functional"

using namespace std;


#include "vector"
#include <type_traits>

using namespace std;

#include "vector"

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        vector<int> res{};
        for (int i = 1; i < arr[0]; i++) {
            res.push_back(i);
            if (res.size() == k) {
                return res[k - 1];
            }
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            for (int k1 = arr[i] + 1; k1 < arr[i + 1]; k1++) {
                res.push_back(k1);
                if (res.size() == k) {
                    return res[k - 1];
                }
            }
        }
        for (int i = arr[arr.size() - 1] + 1; i < 5000; i++) {
            res.push_back(i);
            if (res.size() == k) {
                return res[k - 1];
            }
        }
        return 0;
    }
};
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5


int main() {
    vector<int> rt{2, 3, 4, 7, 11};
    Solution r{};
    int t5 = r.findKthPositive(rt, 5);
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