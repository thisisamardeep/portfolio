//
// Created by amardeep on 18/02/24.
//

#include "vector"
using namespace std;
vector<vector<int>> findpermutations(vector<int> &input, size_t n, vector<int> temp,
                                     vector<vector<int>> finalresult) {
    if (temp.size() == n) {
        finalresult.push_back(temp);
    }
    return {};
};
int main() {
    vector<int> input{1, 2, 4};
    size_t n = 3;
    vector<int> temp{};
    vector<vector<int>> finalresult{};
    vector<vector<int>> result = findpermutations(input, n, temp, finalresult);
    return 0;
}