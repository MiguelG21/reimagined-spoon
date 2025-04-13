#include "header.h"

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "DFS Preorder: ";
    tree.printPreorder();

    std::cout << "DFS Inorder: ";
    tree.printInorder();

    std::cout << "DFS Postorder: ";
    tree.printPostorder();

    std::cout << "BFS: ";
    tree.printBFS();

    std::cout << "Total Nodes: " << tree.totalNodes() << std::endl;
    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;

    return 0;
}
