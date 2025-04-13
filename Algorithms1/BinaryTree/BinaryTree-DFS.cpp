#include "header.h"

void dfsPreorder(Node* node) {
    if (node) {
        std::cout << node->data << " ";
        dfsPreorder(node->left);
        dfsPreorder(node->right);
    }
}

void dfsInorder(Node* node) {
    if (node) {
        dfsInorder(node->left);
        std::cout << node->data << " ";
        dfsInorder(node->right);
    }
}

void dfsPostorder(Node* node) {
    if (node) {
        dfsPostorder(node->left);
        dfsPostorder(node->right);
        std::cout << node->data << " ";
    }
}
