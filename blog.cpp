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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {

        std::vector<int> res{};

        std::queue<TreeNode *> myqueue{};
        myqueue.push(root);
        TreeNode *frontelement{};
        int length_of_queue = myqueue.size();

        while (myqueue.size() != 0) {
            length_of_queue = myqueue.size();
            for (int i = 0; i < length_of_queue; i++) {
                frontelement = myqueue.front();
                res.push_back(frontelement->val);
                if (frontelement->left != nullptr) {
                    myqueue.push(frontelement->left);
                }
                if (frontelement->right != nullptr) {
                    myqueue.push(frontelement->right);
                }
                myqueue.pop();
            }
        }

        std::sort(res.begin(), res.end());
        int fpointer = 0;
        int spointer = res.size()-1;
        while (fpointer < spointer) {
            if (res[fpointer] + res[spointer] == k) {
                return true;
            }
            if (res[fpointer] + res[spointer] < k) {
                fpointer++;
            } else {
                spointer--;
            }
        }

        return false;
    }
};

int main() {
    TreeNode t5{5};
    TreeNode t3{3};
    TreeNode t2{2};
    TreeNode t4{4};
    TreeNode t6{6};
    TreeNode t7{7};

    t5.left = &t3;
    t5.right = &t6;
    t3.left = &t2;
    t3.right = &t4;
    t6.right = &t7;

    Solution dfr{};
    auto rtttt = dfr.findTarget(&t5,9);

    return 0;
}