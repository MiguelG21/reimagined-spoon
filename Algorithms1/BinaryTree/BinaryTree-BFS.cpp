#include "header.h"
#include <queue>

void bfs(Node* node) {
    if (node == nullptr) return;

    std::queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}
