#include "header.h"

// BinaryAVL constructor
BinaryAVL::BinaryAVL() : BinaryTree() {}

// AVL insert function, overrides the base class insert
void BinaryAVL::insert(Node*& node, int value, Node* parent) {
    if (node == nullptr) {
        node = new Node(value, parent);
    }
    else if (value < node->data) {
        insert(node->left, value, node);
    }
    else {
        insert(node->right, value, node);
    }

    // Balance the node after insertion
    node = balance(node);
}

// AVL balancing function
Node* BinaryAVL::balance(Node* node) {
    // Calculate the balance factor
    int balanceFactor = getBalanceFactor(node);

    // Left heavy case
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);  // Left-Right case
        }
        return rotateRight(node);  // Left-Left case
    }

    // Right heavy case
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);  // Right-Left case
        }
        return rotateLeft(node);  // Right-Right case
    }

    return node;  // Already balanced
}

// Get the balance factor of a node
int BinaryAVL::getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Left rotation
Node* BinaryAVL::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->left = x;
    y->parent = x->parent;
    x->parent = y;

    // Update heights
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return y;  // New root
}

// Right rotation
Node* BinaryAVL::rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr) {
        x->right->parent = y;
    }
    x->right = y;
    x->parent = y->parent;
    y->parent = x;

    // Update heights
    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;  // New root
}

// Override insert function in BinaryAVL class
void BinaryAVL::insert(int value) {
    insert(root, value, nullptr);  // Insert and balance the tree
}

