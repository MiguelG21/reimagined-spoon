#include <iostream>
#include <list>
#include <string>

class HashTable {
    static const int hashGroups = 10;
    std::list<std::pair<int, std::list<std::string>>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key) const;
    void insertItem(int key, std::string value);
    void removeItem(int key, std::string value);
    std::list<std::string> searchTable(int key) const;
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

    for (auto& pair : cell) {
        if (pair.first == key) {
            pair.second.push_back(value);
            std::cout << "Value added to existing key\n";
            return;
        }
    }

    cell.emplace_back(key, std::list<std::string>{value});
    std::cout << "New key with value inserted\n";
}

void HashTable::removeItem(int key, std::string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];

    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            auto& valList = it->second;
            valList.remove(value); // removes all matching values

            if (valList.empty()) {
                cell.erase(it); // delete the entire pair if no more values
                std::cout << "Key and value removed (no more values left)\n";
            }
            else {
                std::cout << "Value removed from key\n";
            }
            return;
        }
    }

    std::cout << "Key not found\n";
}


void HashTable::printTable() const {
    for (int i = 0; i < hashGroups; ++i) {
        for (const auto& pair : table[i]) {
            std::cout << "Key: " << pair.first << " -> ";
            for (const auto& val : pair.second) {
                std::cout << val << ", ";
            }
            std::cout << "\n";
        }
    }
}


std::list<std::string> HashTable::searchTable(int key) const {
    int hashValue = hashFunction(key);
    const auto& cell = table[hashValue];

    for (const auto& pair : cell) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return {};
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