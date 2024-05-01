

We need to solve this  [Zig Zag](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

c++ solution
leave order traversal


![amar33](tree.png)

Left to Right (Top to Bottom) Using Queues





```cpp
#include "queue"
void levelOrder(std::vector<int> &res, Node *&root) {
    std::queue<Node *> myqueu{};
    myqueu.push(root);
    while (!myqueu.empty()) {
        Node *frontElement = myqueu.front();
        myqueu.pop();
        res.push_back(frontElement->data);
        if (frontElement->left != nullptr) {
            myqueu.push(frontElement->left);
        }
        if (frontElement->right != nullptr) {
            myqueu.push(frontElement->right);
        }
    }
}
```

Pre Order Traversal


