# Hash Table Implementation in C++

Two implementations of a **Hash Table** in C++:
- One where each **key maps to a single value**
- Another where each **key maps to a list of values** called **chained Hash table**

---

##  What is a Hash Table?

A **Hash Table** is a data structure that stores key-value pairs. It uses a **hash function** to map keys to indices (buckets) in an array, allowing for efficient **insertion, deletion, searching,** and **retrieval**.

Hash tables typically offer:
- **Average-case O(1)** time complexity for insert, delete, and search
- Efficient lookup with proper collision handling (here we use **separate chaining** with `std::list`)

---

## Implementation 1 — One Value per Key

### Functions

| Function                 | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| `isEmpty()`              | Checks if the table has any elements                                        |
| `hashFunction(int)`      | Returns hash index (key modulo number of groups)                            |
| `insertItem(int, string)`| Adds a key-value pair or replaces value if key already exists               |
| `removeItem(int)`        | Deletes the key-value pair if found                                         |
| `searchTable(int)`       | Returns the value for a given key, or "Not found" if missing                |
| `printTable()`           | Prints all key-value pairs in the table                                     |

### Time and Space Complexity

| Function                 | Time Complexity | Space Complexity |
|--------------------------|------------------|-------------------|
| `isEmpty()`              | O(n)             | O(1)              |
| `hashFunction(int)`      | O(1)             | O(1)              |
| `insertItem()`           | O(n/k)           | O(1)              |
| `removeItem()`           | O(n/k)           | O(1)              |
| `searchTable()`          | O(n/k)           | O(1)              |
| `printTable()`           | O(n)             | O(1)              |

> `n = number of total items`, `k = number of buckets` (hash groups)

---

## Implementation 2 — Multiple Values per Key

### Functions

| Function                         | Description                                                                 |
|----------------------------------|-----------------------------------------------------------------------------|
| `isEmpty()`                      | Checks if the table has any key-value pairs                                 |
| `hashFunction(int)`              | Computes hash index from key                                                |
| `insertItem(int, string)`        | Adds value to a key; if key exists, appends to its value list               |
| `removeItem(int, string)`        | Removes a specific value from a key; removes key if value list becomes empty|
| `searchTable(int)`               | Returns a list of all values for a given key                                |
| `printTable()`                   | Prints all key-value lists in the table                                     |

### Time and Space Complexity

| Function                 | Time Complexity | Space Complexity |
|--------------------------|------------------|-------------------|
| `isEmpty()`              | O(n)             | O(1)              |
| `hashFunction(int)`      | O(1)             | O(1)              |
| `insertItem()`           | O(n/k)           | O(1)              |
| `removeItem()`           | O(n/k + m)       | O(1)              |
| `searchTable()`          | O(n/k)           | O(m)              |
| `printTable()`           | O(n + m)         | O(1)              |

> `n = number of key entries`, `m = total number of values stored per key`

---

## Notes
- Both implementations use **separate chaining** via `std::list` for collision handling.
- Second implementation adds support for **multi-mapping** (one key → many values).
- Functions are marked `const` if they do **not modify** the internal state.

---
