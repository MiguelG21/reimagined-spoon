# Binary Tree Implementation

A **binary tree** is a tree data structure where each node has at most two children, referred to as the left and right children.

## File Structure and Explanation

The project is divided into the following files:

- **`Header.h`**: Header file containing the declarations for the `Node` structure, `BinaryTree` class, and function prototypes for DFS and BFS traversals.
- **`BinaryTree.cpp`**: Implements the core functionality of the `BinaryTree` class, including insertion, deletion, and traversal methods.
- **`BinaryTree-DFS.cpp`**: Implements the Depth-First Search (DFS) traversal functions (preorder, inorder, and postorder).
- **`BinaryTree-BFS.cpp`**: Implements the Breadth-First Search (BFS) traversal.
- **`main.cpp`**: Contains the main function to test the binary tree functionality with sample input and display traversal results.

### Conceptual Division

- **DFS Functions (DFS.cpp)**: 
  - Performs Depth-First Search traversals: Preorder, Inorder, and Postorder.
  - These functions explore the tree by visiting nodes along a path from the root to a leaf before backtracking.
  
- **BFS Function (BFS.cpp)**:
  - Performs Breadth-First Search traversal.
  - This function explores the tree level by level, visiting all nodes at one level before moving to the next.

### Function Overview

| **Function Name**        | **Description**                                                                                  |
|--------------------------|--------------------------------------------------------------------------------------------------|
| `insert(int value)`       | Inserts a value into the binary tree, maintaining the binary search tree property.               |
| `search(int value)`       | Searches for a value in the binary tree and returns `true` if found, `false` otherwise.         |
| `deleteValue(int value)`  | Deletes a node with the specified value from the binary tree while maintaining the binary search tree property. |
| `printPreorder()`         | Prints the tree nodes in **Preorder** (Root -> Left -> Right) using DFS.                         |
| `printInorder()`          | Prints the tree nodes in **Inorder** (Left -> Root -> Right) using DFS.                         |
| `printPostorder()`        | Prints the tree nodes in **Postorder** (Left -> Right -> Root) using DFS.                       |
| `printBFS()`              | Prints the tree nodes in **Level-Order** (BFS traversal).                                        |
| `totalNodes()`            | Returns the total number of nodes in the tree.                                                   |
| `getHeight()`             | Returns the height of the tree (the longest path from the root to a leaf).                      |

### Time and Space Complexity

| **Function Name**        | **Time Complexity**              | **Space Complexity**             |
|--------------------------|----------------------------------|----------------------------------|
| `insert(int value)`       | O(h) - where h is the height of the tree. | O(h) - recursive call stack depth. |
| `search(int value)`       | O(h)                             | O(h) - recursive call stack depth. |
| `deleteValue(int value)`  | O(h)                             | O(h) - recursive call stack depth. |
| `printPreorder()`         | O(n) - where n is the number of nodes. | O(h) - recursive call stack depth. |
| `printInorder()`          | O(n)                             | O(h) - recursive call stack depth. |
| `printPostorder()`        | O(n)                             | O(h) - recursive call stack depth. |
| `printBFS()`              | O(n)                             | O(n) - queue used for level order traversal. |
| `totalNodes()`            | O(n)                             | O(h) - recursive call stack depth. |
| `getHeight()`             | O(n)                             | O(h) - recursive call stack depth. |

### Output of the `main` File

When main is run, the output will be as follows:
```
  DFS Preorder: 50 30 20 40 70 60 80 
  DFS Inorder: 20 30 40 50 60 70 80
  DFS Postorder: 20 40 30 60 80 70 50
  BFS: 50 30 70 20 40 60 80
  Total Nodes: 7
  Height of the tree: 3
```
---

- **DFS Preorder**: The nodes are printed as they are visited in **Preorder** traversal (Root -> Left -> Right).
- **DFS Inorder**: The nodes are printed in **Inorder** traversal (Left -> Root -> Right).
- **DFS Postorder**: The nodes are printed in **Postorder** traversal (Left -> Right -> Root).
- **BFS**: The nodes are printed in **Level-Order** (BFS traversal).
- **Total Nodes**: The total number of nodes in the tree.
- **Height of the Tree**: The height (or depth) of the tree from the root to the farthest leaf node.

---
