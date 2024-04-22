//#include "set"


#include "queue"


class Node {
public:
    Node(int data) : data(data), left(nullptr), right(nullptr) {

    }

    int data;
    Node *left;
    Node *right;
};

void levelOrder(std::vector<int> &res, Node *&root) {
    std::queue<Node *> myqueu{};
    myqueu.push(root);
    while (!myqueu.empty()) {
        Node *frontElement = myqueu.front();
        myqueu.pop();
        res.push_back(frontElement->data);
        if (frontElement->right != nullptr) {
            myqueu.push(frontElement->right);
        }
        if (frontElement->left != nullptr) {
            myqueu.push(frontElement->left);
        }

    }
}

int main() {
    Node *root = new Node(3);
    Node *root9 = new Node(9);
    Node *root20 = new Node(20);
    Node *root15 = new Node(15);
    Node *root7 = new Node(7);
    root->left = root9;
    root->right = root20;
    root20->left = root15;
    root20->right = root7;
    std::vector<int> res{};
    levelOrder(res, root);


    return 0;
}