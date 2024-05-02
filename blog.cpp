//#include "set"

#include "iostream"
#include "vector"
#include "cassert"

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>> &logs) {
        vector<int> mypopulation(2051, 0);
        int earlier_year = 0;
        int max_population = 0;
        for (int i = 0; i < logs.size(); i++) {
            for (int j = logs[i][0]; j < logs[i][1]; j++) {
                mypopulation[j] = mypopulation[j] + 1;
                if (max_population < mypopulation[j]) {
                    max_population = mypopulation[j];
                    earlier_year = j;
                } else if (max_population == mypopulation[j]) {
                    if (earlier_year > j) {
                        earlier_year = j;
                    }
                } else {

                }

            }

        }
//        assert(2 == 2);
        assert(mypopulation[2005] == 3);
        assert(mypopulation[2040] == 3);

        return earlier_year;

    }
};

int main() {


    vector<vector<int>> logs{{2033, 2034},
                             {2039, 2047},
                             {1998, 2042},
                             {2047, 2048},
                             {2025, 2029},
                             {2005, 2044},
                             {1990, 1992},
                             {1952, 1956},
                             {1984, 2014}};


    int rt = (new Solution)->maximumPopulation(logs);
    return 0;
}