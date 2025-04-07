# Max Heap Implementation in C++

**Manual implementation of a Max Heap** in C++ using a dynamic array (via `std::vector`). It avoids STL heap or priority queue structures for practice purpose. This implementation supports insertion, deletion, extraction of the maximum value, heapification from an array, and more.

---
### Recent Refactor

The heap implementation was recently refactored to remove manual size tracking (`_size`) and instead use the built-in `vect.size()` method for size management. This change improves **readability** and **maintainability**, as well as reduces potential for errors associated with manual size management.

- All functions were updated to rely on `vect.size()` instead of `_size`.
- The recursion in `shiftUp()` was simplified for clearer logic, especially at the root node.
---

## Function Descriptions

| Function | Description |
|----------|-------------|
| `isEmpty()` | Checks if the heap is empty. |
| `getMax()` | Returns the maximum value in the heap. |
| `insertItem(int val)` | Inserts a new value into the heap. |
| `shiftUp(int i)` | Recursively moves the element at index `i` up to restore heap property. |
| `extractMax()` | Removes and returns the maximum value from the heap. |
| `shiftDown(int i)` | Recursively moves the element at index `i` down to restore heap property. |
| `deleteItem(int val)` | Deletes the first occurrence of `val` from the heap. |
| `heapify(const std::vector<int>& data)` | Builds a heap from an unsorted array. |
| `printHeap()` | Prints all current elements of the heap. |

---

## Time and Space Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|------------------|------------------|
| `insertItem` | O(log n) | O(1) |
| `extractMax` | O(log n) | O(1) |
| `getMax` | O(1) | O(1) |
| `shiftUp` | O(log n) | O(1) |
| `shiftDown` | O(log n) | O(1) |
| `deleteItem` | O(n) (search) + O(log n) (heap restore) | O(1) |
| `heapify` | O(n) | O(n) |
| `isEmpty` | O(1) | O(1) |
| `printHeap` | O(n) | O(1) |

---

## Sample Output

Output from the provided "test" `main()` function:
Correct 98 62 25 Correct

---

## Notes

- Internally, the heap is stored in a `std::vector<int>` starting at index 1. Index 0 holds a dummy `-1` value to simplify parent/child index calculations.
- This heap only supports integers and maintains the **Max Heap** property.
---
