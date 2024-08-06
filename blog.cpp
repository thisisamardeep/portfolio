#include <functional>
#include "iostream"
#include "thread"
#include "vector"
#include "queue"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
using namespace std;
#include "vector"
int main() {

    vector<int> myvector;
    myvector.push_back(3);
    myvector.push_back(4);
    myvector.push_back(1);
    myvector.push_back(7);
    myvector.push_back(3);
    std::cout << myvector.back() << std::endl;
    return 0;
}