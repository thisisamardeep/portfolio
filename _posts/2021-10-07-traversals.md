---
title: All types of tree traversals 
published: true
tags: [ leetcode ]
readtime: true
permalink: "/tree-traversals-bfs-dfs-all-three"
share-description: Tree Traversals
comments: false
---




We will first do BF Traversal in following ways

Left to Right (Top to Bottom)

Right to Left (Top to Bottom)



![amar33](img/tree.png)

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

Right to Left (Top to Bottom) Using Queues

```cpp
#include "queue"
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
```

Now we do a pre order traversal of a Binary Tree.


```cpp
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
```


Now we do a in order traversal of a Binary Tree.


```cpp
class Solution {
public:
    void preOrder(Node *&node, vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr) {
            preOrder(node->left, result);
        }
                result.push_back(node->data);

        if (node->right != nullptr) {
            preOrder(node->right, result);
        }
    }
};
```


Now we do a post order traversal of a Binary Tree.


```cpp
class Solution {
public:
    void preOrder(Node *&node, vector<int> &result) {
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr) {
            preOrder(node->left, result);
        }

        if (node->right != nullptr) {
            preOrder(node->right, result);
        }
                        result.push_back(node->data);

    }
};
```