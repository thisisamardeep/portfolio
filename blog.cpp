//#include "set"

#include "iostream"
#include "vector"
#include "cassert"

using namespace std;

class Solution {
public:
    void myrec(int m, int n, int i, int j) {

    }

public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        myrec(m, n, 0, 0);
        int max_area = 0;
        return max_area;
    }
};

int main() {

    vector<vector<char>> matrix1{{'1', '1', '1', '1', '0'},
                                 {'1', '1', '1', '1', '0'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'0', '0', '1', '1', '1'}};

    Solution er{};
    int res = er.maximalSquare(matrix1);
    return 0;
}