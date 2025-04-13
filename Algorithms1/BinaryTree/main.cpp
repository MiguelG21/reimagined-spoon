#include "header.h"
int main() {
    // Testing BinaryTree with duplicate insertions
    std::cout << "Testing BinaryTree (Duplicate Insertions):" << std::endl;

    BinaryTree tree;
    // Inserting values with duplicates
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(50);  // Duplicate value
    tree.insert(20);
    tree.insert(40);

    std::cout << "DFS Preorder: ";
    tree.printPreorder();

    std::cout << "DFS Inorder: ";
    tree.printInorder();

    std::cout << "DFS Postorder: ";
    tree.printPostorder();

    std::cout << "BFS: ";
    tree.printBFS();

    std::cout << "Tree is balanced: " << (tree.isBalanced() ? "Yes" : "No") << std::endl;

    std::cout << "Total Nodes: " << tree.totalNodes() << std::endl;
    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;

    return 0;
}

