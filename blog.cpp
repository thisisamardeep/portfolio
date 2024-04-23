//#include "set"


#include "queue"
#include "string"

using namespace std;

class Node {
public:
    Node(int data) : data(data), left(nullptr), right(nullptr) {

    }

    int data;
    Node *left;
    Node *right;
};

class Solution {
public:
    void preOrder(Node *&node, vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(node->data);
        if (node->left != nullptr) {
            preOrder(node->left, result);
        }
        if (node->right != nullptr) {
            preOrder(node->right, result);
        }
    }
};

int main() {
    Node *root = new Node(3);
    Node *root9 = new Node(9);
    root9->left=new Node(88);
    Node *root20 = new Node(20);
    Node *root15 = new Node(15);
    Node *root7 = new Node(7);
    root->left = root9;
    root->right = root20;
    root20->left = root15;
    root20->right = root7;
    Solution s{};
    vector<int> result{};
    s.preOrder(root, result);

    return 0;
}