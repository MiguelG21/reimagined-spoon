# Doubly Linked List (C++)

This project contains a custom implementation of a doubly linked list in C++. It provides all fundamental operations to manage and manipulate nodes in both directions (forward and backward), ideal for learning purposes or practicing data structure fundamentals.

---

## Features

This implementation includes:

- Node insertion (front, end, specific position, before/after a value)
- Node deletion (front, end, specific position)
- Search and replace
- Swapping values between nodes
- List reversal
- Check for existence and emptiness
- Forward and backward printing
- Memory-safe clearing and destructor

---

## List of Functions

| Function               | Description                                             |
|------------------------|---------------------------------------------------------|
| `addFront(value)`      | Inserts a new node at the beginning of the list         |
| `addEnd(value)`        | Appends a new node at the end of the list               |
| `addAt(value, pos)`    | Inserts a node at the given position                    |
| `insertAfterValue(val, target)` | Inserts a node after the node with target value    |
| `insertBeforeValue(val, target)`| Inserts a node before the node with target value   |
| `replaceData(val, pos)`| Replaces the value at the given index                   |
| `switchValue(p1, p2)`  | Swaps values between two given positions                |
| `deleteFront()`        | Removes the first node                                  |
| `deleteEnd()`          | Removes the last node                                   |
| `deleteAt(pos)`        | Removes the node at a specific position                 |
| `findNode(val)`        | Returns the pointer to the node containing the value    |
| `findIndex(val)`       | Returns the index of the node with the given value      |
| `contains(val)`        | Returns true if the value exists in the list            |
| `isEmpty()`            | Checks if the list is empty                             |
| `printForward()`       | Prints the list from head to tail                       |
| `printBackward()`      | Prints the list from tail to head                       |
| `reverse()`            | Reverses the list in-place                              |
| `clear()`              | Removes all elements from the list                      |

---

## Time & Space Complexity

| Function               | Time Complexity | Space Complexity |
|------------------------|------------------|------------------|
| `addFront`             | O(1)             | O(1)             |
| `addEnd`               | O(1)             | O(1)             |
| `addAt`                | O(n)             | O(1)             |
| `insertAfterValue`     | O(n)             | O(1)             |
| `insertBeforeValue`    | O(n)             | O(1)             |
| `replaceData`          | O(n)             | O(1)             |
| `switchValue`          | O(n)             | O(1)             |
| `deleteFront`          | O(1)             | O(1)             |
| `deleteEnd`            | O(1)             | O(1)             |
| `deleteAt`             | O(n)             | O(1)             |
| `findNode`             | O(n)             | O(1)             |
| `findIndex`            | O(n)             | O(1)             |
| `contains`             | O(n)             | O(1)             |
| `isEmpty`              | O(1)             | O(1)             |
| `printForward`         | O(n)             | O(1)             |
| `printBackward`        | O(n)             | O(1)             |
| `reverse`              | O(n)             | O(1)             |
| `clear`                | O(n)             | O(1)             |

---

