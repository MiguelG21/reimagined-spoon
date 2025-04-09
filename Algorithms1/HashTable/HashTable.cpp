#include <iostream>
#include <list>
#include <string>

class HashTable {
    static const int hashGroups = 10;
    std::list<std::pair<int, std::string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, std::string value);
    void removeItem(int key);
   // std::string(searchTable(int key));
    void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, std::string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto it = begin(cell);
    bool keyExist = false;
    for (; it != end(cell); it++) {
        if(it->first == key) {
            keyExist = true;
            it->second = value;
            std::cout << "Value replaced" << std::endl;
            break;
        }
    }
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto it = begin(cell);
    bool keyExist = false;
    for (; it != end(cell); it++) {
        if (it->first == key) {
            keyExist = true;
            it = cell.erase(it);
            std::cout << "Value deleted" << std::endl;
            break;
        }
    }
    return;
}

void printTable() {};

int main()
{
    std::cout << "Hello World!\n";
}