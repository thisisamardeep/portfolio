//#include "set"

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>> &logs) {


        return 45;

    }
};

int main() {

    vector<vector<int>> logs{};
    vector<int> t1{1993, 1999};
    vector<int> t2{2000, 2010};
    logs.push_back(t1);
    logs.push_back(t2);

    int rt = (new Solution)->maximumPopulation(logs);
    return 0;
}