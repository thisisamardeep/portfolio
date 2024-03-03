//https://leetcode.com/contest/weekly-contest-386/problems/find-the-largest-area-of-square-inside-two-rectangles/








//take any 2 rectables find if interaction matches
// take any 2 rectabgles find if lenght is not equal to breasth
// tske any 2 rectables return area


#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft,
                                vector<vector<int>> &topRight) {
        long long finalresult = 0;
        for (size_t i = 0; i < bottomLeft.size(); i++) {

            long long first_leftdown_x = bottomLeft[i][0];
            long long first_leftdown_y = bottomLeft[i][1];

            long long first_topRight_x = topRight[i][0];
            long long first_topRight_y = topRight[i][1];

            //            i is the index of first rectangle and j is the index
            //            of the second rectangle

            for (size_t j = i + 1; j < bottomLeft.size(); j++) {

                long long second_leftdown_x = bottomLeft[j][0];
                long long second_leftdown_y = bottomLeft[j][1];

                long long second_topRight_x = topRight[j][0];
                long long second_topRight_y = topRight[j][1];

                // Case1 i is superset of j
                //                std::cout << first_leftdown_x << std::endl;
                if ((first_leftdown_x <= second_leftdown_x) &&
                    (first_leftdown_y <= second_leftdown_y) &&
                    (first_topRight_x >= second_topRight_x) &&
                    (first_topRight_y >= second_topRight_y)) {
                    long long length = second_topRight_x - second_leftdown_x;
                    long long width = second_topRight_y - second_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);

                } else if ((first_leftdown_x >= second_leftdown_x) &&
                           (first_leftdown_y >= second_leftdown_y) &&
                           (first_topRight_x <= second_topRight_x) &&
                           (first_topRight_y <= second_topRight_y)) {

                    // Case1 j is superset of i
                    long long length = first_topRight_x - first_leftdown_x;
                    long long width = first_topRight_y - first_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);

                } else if ((first_topRight_x <= second_leftdown_x) &&
                           (first_topRight_y <= second_leftdown_y)) {
                    // Case1 i is disjoint and bottom left of j

                } else if ((second_topRight_x <= first_leftdown_x) &&
                           (second_topRight_y <= first_leftdown_y)) {
                    // Case1 i is disjoint and top right  of j

                } else if ((first_leftdown_x >= second_leftdown_x) &&
                           (first_leftdown_x <= second_topRight_x) &&
                           (first_leftdown_y >= second_leftdown_y) &&
                           (first_leftdown_y <= second_topRight_y)) {
                    long long length = second_topRight_x - first_leftdown_x;
                    long long width = second_topRight_y - first_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);

                    // Case1 i is disjoint and top right  of j

                } else if ((second_leftdown_x >= first_leftdown_x) &&
                           (second_leftdown_x <= first_topRight_x) &&
                           (second_leftdown_y >= first_leftdown_y) &&
                           (second_leftdown_y <= first_topRight_y)) {
                    // Case1 i is disjoint and top right  of j
                    long long length = first_topRight_x - second_leftdown_x;
                    long long width = first_topRight_y - second_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);

                } else if ((first_leftdown_x >= second_leftdown_x) &&
                           (first_leftdown_x <= second_topRight_x) &&
                           (first_leftdown_y <= second_leftdown_y) &&
                           (first_topRight_y <= second_topRight_y) &&
                           (first_topRight_y >= second_leftdown_y)) {
                    // Case1 i is disjoint and top right  of j
                    long long length = first_topRight_x - first_leftdown_x;
                    long long width = first_topRight_y - second_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);

                } else if ((second_leftdown_x >= first_leftdown_x) &&
                           (second_leftdown_x <= first_topRight_x) &&
                           (second_leftdown_y <= first_leftdown_y) &&
                           (second_topRight_y <= first_topRight_y) &&
                           (second_topRight_y >= first_leftdown_y)) {
                    // Case1 i is disjoint and top right  of j
                    long long length = second_topRight_x - second_leftdown_x;
                    long long width = second_topRight_y - first_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);
                } else if ((second_leftdown_x >= first_leftdown_x) &&
                           (second_leftdown_x <= first_topRight_x) &&
                           (second_leftdown_y <= first_leftdown_y) &&
                           (second_topRight_y <= first_topRight_y) &&
                           (second_topRight_y >= first_leftdown_y)) {
                    // Case1 i is disjoint and top right  of j
                    long long length = second_topRight_x - second_leftdown_x;
                    long long width = second_topRight_y - first_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);
                } else if ((first_leftdown_x <= second_leftdown_x) &&
                           (first_leftdown_y >= second_leftdown_y) &&
                           (first_leftdown_y <= second_topRight_y) &&
                           (first_topRight_x >= second_leftdown_x) &&
                           (first_topRight_x <= second_topRight_x)) {
                    // Case1 i is disjoint and top right  of j
                    long long length = first_topRight_x - second_leftdown_x;
                    long long width = first_topRight_y - first_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);
                } else if ((second_leftdown_x <= first_leftdown_x) &&
                           (second_leftdown_y >= first_leftdown_y) &&
                           (second_leftdown_y <= first_topRight_y) &&
                           (second_topRight_x >= first_leftdown_x) &&
                           (second_topRight_x <= first_topRight_x)) {
                    // Case1 i is disjoint and top right  of j
                    long long length = second_topRight_x - first_leftdown_x;
                    long long width = second_topRight_y - second_leftdown_y;
                    long long size = min(length, width);
                    finalresult = max(finalresult, size * size);
                }
            }
        }
        return finalresult;
    }
};


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