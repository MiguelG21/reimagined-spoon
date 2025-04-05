# Linked List in C++

This is a simple template implementation of a **singly linked list** in C++.

## Features

This linked list class supports the following operations:

- **`addFront(value)`** – Adds a node at the beginning of the list.
- **`addEnd(value)`** – Adds a node at the end of the list.
- **`addAt(value, position)`** – Inserts a node at a specific position.
- **`deleteAt(position)`** – Removes the node at a given position.
- **`find(value)`** – Searches for the first occurrence of a value.
- **`printList()`** – Prints all elements in the list from head to tail.

Memory management with a destructor that deallocates all nodes when the list is destroyed.

## Time & Space Complexity

| Operation       | Time Complexity | Space Complexity |
|----------------|------------------|------------------|
| `addFront`      | O(1)             | O(1)             |
| `addEnd`        | O(1)             | O(1)             |
| `addAt`         | O(n)             | O(1)             |
| `deleteAt`      | O(n)             | O(1)             |
| `find`          | O(n)             | O(1)             |
| `printList`     | O(n)             | O(1)             |

> *where n is the number of nodes in the list.*

## Usage

The `main()` function contains a basic usage example:

```cpp
linkedlist myList;
myList.addEnd(10);
myList.addEnd(20);
myList.addFront(5);
myList.printList();  // Output: 5 -> 10 -> 20 -> Null
