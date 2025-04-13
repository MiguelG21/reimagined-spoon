#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <queue>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;  

    Node(int value, Node* parent = nullptr);
};

class BinaryTree {
protected:
    Node* root;

    virtual void insert(Node*& node, int value, Node* parent);
    Node* search(Node* node, int value);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* node, int value);

    bool isBalanced(Node* node);
    int checkBalance(Node* node);
    int countNodes(Node* node);
    int height(Node* node);

public:
    BinaryTree();
    virtual void insert(int value);  // Virtual so that BinaryAVL can override it
    bool search(int value);
    void deleteValue(int value);
    void printPreorder();
    void printInorder();
    void printPostorder();
    void printBFS();
    bool isBalanced();
    int totalNodes();
    int getHeight();
};

class BinaryAVL : public BinaryTree {
protected:
    void insert(Node*& node, int value, Node* parent) override;  // Overriding insert for AVL

    int getBalanceFactor(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* balance(Node* node);

public:
    BinaryAVL();
    void insert(int value) override;  // Override insert to handle AVL balancing
};

void dfsPreorder(Node* node);
void dfsInorder(Node* node);
void dfsPostorder(Node* node);
void bfs(Node* node);

#endif  // HEADER_H
