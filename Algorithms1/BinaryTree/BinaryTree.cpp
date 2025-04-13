#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value, Node* parent = nullptr)
        : data(value), left(nullptr), right(nullptr), parent(parent) {
    }
};

class BinaryTree {
private:
    Node* root;

    void insert(Node*& node, int value, Node* parent) {
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

    Node* search(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    Node* minValueNode(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
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

    void preorder(Node* node) {
        if (node) {
            std::cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->data << " ";
        }
    }

    int countNodes(Node* node) {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        insert(root, value, nullptr);
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void printPreorder() {
        preorder(root);
        std::cout << std::endl;
    }

    void printPostorder() {
        postorder(root);
        std::cout << std::endl;
    }

    int totalNodes() {
        return countNodes(root);
    }

    int getHeight() {
        return height(root);
    }
};

