#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value, Node* parent = nullptr);
};

class BinaryTree {
private:
    Node* root;

    // Private methods for inserting, deleting, searching, etc.
    void insert(Node*& node, int value, Node* parent);
    Node* search(Node* node, int value);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* node, int value);

    int countNodes(Node* node);
    int height(Node* node);

public:
    BinaryTree();
    void insert(int value);
    bool search(int value);
    void deleteValue(int value);
    void printPreorder();
    void printInorder();
    void printPostorder();
    void printBFS();
    int totalNodes();
    int getHeight();
};

void dfsPreorder(Node* node);
void dfsInorder(Node* node);
void dfsPostorder(Node* node);

void bfs(Node* node);

#endif
