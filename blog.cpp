//#include "set"

#include "iostream"
#include "vector"
#include "cassert"
//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        return 56;
    }
};

int main() {

    TreeNode t3 = TreeNode(3);
    TreeNode t9 = TreeNode(9);
    TreeNode t20 = TreeNode(20);
    TreeNode t15 = TreeNode(15);
    TreeNode t7 = TreeNode(7);
    t3.left = &t9;
    t3.right = &t20;
    t20.left = &t15;
    t20.left = &t7;
    Solution er{};
    int res = er.minDepth(&t3);
    return 0;
}