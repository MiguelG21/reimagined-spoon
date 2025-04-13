#include "header.h"
#include <queue>

// Node constructor
Node::Node(int value, Node* parent)
    : data(value), left(nullptr), right(nullptr), parent(parent) {
}

// BinaryTree constructor
BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(Node*& node, int value, Node* parent) {
    if (node == nullptr) {
        node = new Node(value, parent);
    }
    else if (value < node->data) {
        insert(node->left, value, node);
    }
    else {
        insert(node->right, value, node);
    }
}

void BinaryTree::insert(int value) {
    insert(root, value, nullptr);
}

bool BinaryTree::search(int value) {
    return search(root, value) != nullptr;
}

Node* BinaryTree::search(Node* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }
    if (value < node->data)
        return search(node->left, value);
    else
        return search(node->right, value);
}

Node* BinaryTree::minValueNode(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

Node* BinaryTree::deleteNode(Node* node, int value) {
    if (node == nullptr)
        return node;

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

int BinaryTree::countNodes(Node* node) {
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int BinaryTree::height(Node* node) {
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Print functions
void BinaryTree::printPreorder() {
    dfsPreorder(root);
    std::cout << std::endl;
}

void BinaryTree::printInorder() {
    dfsInorder(root);
    std::cout << std::endl;
}

void BinaryTree::printPostorder() {
    dfsPostorder(root);
    std::cout << std::endl;
}

void BinaryTree::printBFS() {
    bfs(root);
    std::cout << std::endl;
}

int BinaryTree::totalNodes() {
    return countNodes(root);
}

int BinaryTree::getHeight() {
    return height(root);
}
