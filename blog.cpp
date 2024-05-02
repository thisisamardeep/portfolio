//#include "set"

#include "iostream"
#include "vector"
#include "cassert"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            int days = 0;
            for (int j = i + 1; j < temperatures.size(); j++) {
                days = days + 1;
                if (temperatures[j] > temperatures[i]) {
                    break;
                } else if (j == temperatures.size() - 1) {
                    days = 0;
                }
            }
            res[i] = days;
        }
        return res;
    }
};

int main() {


    vector<int> temp{73, 74, 75, 71, 69, 72, 76, 73};


    vector<int> result = (new Solution)->dailyTemperatures(temp);
    return 0;
}