//https://leetcode.com/contest/weekly-contest-386/problems/find-the-largest-area-of-square-inside-two-rectangles/








//take any 2 rectables find if interaction matches
// take any 2 rectabgles find if lenght is not equal to breasth
// tske any 2 rectables return area


#include "iostream"
#include "vector"

using namespace std;




int main() {


    vector<vector<int>> bottomLeft{{3, 2},
                                   {1, 1},

    };

    vector<vector<int>> topRight{{4, 5},
                                 {5, 4},
    };

    Solution r = Solution{};
    auto rrr = r.largestSquareArea(bottomLeft, topRight);
    std::cout << rrr << std::endl;

    return 0;
}