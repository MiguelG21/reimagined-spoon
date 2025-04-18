#include <iostream>
#include <list>
#include <string>

class HashTable {
    static const int hashGroups = 10;
    std::list<std::pair<int, std::string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key) const;
    void insertItem(int key, std::string value);
    void removeItem(int key);
    std::string searchTable(int key) const;
    void printTable() const;
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

int HashTable::hashFunction(int key) const {
    return key % hashGroups;
}

void HashTable::insertItem(int key, std::string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    bool keyExist = false;
    for (auto it = begin(cell); it != end(cell); it++) {
        if(it->first == key) {
            keyExist = true;
            it->second = value;
            std::cout << "Value replaced" << std::endl;
            break;
        }
    }
    if (!keyExist) {
        cell.emplace_back(key, value);  // <-- insert here
        std::cout << "Value inserted" << std::endl;
    }
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    bool keyExist = false;
    for (auto it = begin(cell); it != end(cell); it++) {
        if (it->first == key) {
            keyExist = true;
            it = cell.erase(it);
            std::cout << "Value deleted" << std::endl;
            break;
        }
    }
    if (!keyExist) {
        std::cout << "Key not found" << std::endl;
    }
    return;
}

void HashTable::printTable() const {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;
        for (auto it = table[i].begin(); it != table[i].end(); it++) {
            std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
        }
    }
};

std::string HashTable::searchTable(int key) const {
    int hashValue = hashFunction(key);
    const auto& cell = table[hashValue];

    for (const auto& pair : cell) {
        if (pair.first == key) {
            return pair.second;
        }
    }

    return "Not found";
}

int main()
{
    HashTable table;
    if (table.isEmpty()) {
        std::cout << "Correct" << std::endl;
    }
    else {
        std::cout << "Error Empty function" << std::endl;
    }

    table.insertItem(958, "Louis");
    table.insertItem(189, "Megatron");
    table.insertItem(504, "Stewie");
    table.insertItem(503, "Brian");
    table.insertItem(503, "Peter");

    table.printTable();
    table.removeItem(189);

    if (table.isEmpty()) {
        std::cout << "Error Empty function" << std::endl;
    }
    else {
        std::cout << "Correct" << std::endl;
    }
}