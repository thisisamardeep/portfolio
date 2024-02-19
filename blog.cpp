//
// Created by amardeep on 18/02/24.
//

#include "vector"

using namespace std;

void swapme(vector<int> &swap_me, size_t i, size_t j) {
    int t1 = swap_me[i];
    swap_me[i] = swap_me[j];
    swap_me[j] = t1;

}

void findpermutations(vector<int> &input, size_t n, vector<int> &temp,
                      vector<vector<int>> &finalresult, int last_fixed_index) {
    if (temp.size() == n) {
        finalresult.push_back(temp);
        return;
    }

    for (size_t i = last_fixed_index; i < n; i++) {
        swapme(input, last_fixed_index, i);
        temp.push_back(input[last_fixed_index]);
        findpermutations(input, n, temp, finalresult, last_fixed_index + 1);
        temp.pop_back();
        swapme(input, i, last_fixed_index);
    }


};

int main() {
    vector<int> input{1, 2, 3};
    size_t n = 3;
    vector<int> temp{};
    vector<vector<int>> finalresult{};
    findpermutations(input, n, temp, finalresult, 0);
    return 0;
}