#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {};
};

class doubleLinkedList {
    Node* head;
    Node* tail;
    int listLength;

public:
    doubleLinkedList(): head(nullptr), tail(nullptr), listLength(0){}
    ~doubleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void addFront(int value) {}
    void addEnd(int value) {}
    void addAt(int value, int position) {}
    void insertAfter(int value, int target) {}
    void insertBefore(int value, int target) {}
    void replace(int value, int position) {}
    void switchValue(int position1, int position2) {}
    void deleteFront() {}
    void deleteEnd() {}
    void deleteAt() {}
    void deleteValue() {}
    int find(int value) {}
    void printForward() {}
    void printBackward() {}
    bool isEmpty() {} //additional implement
    bool contains() {}
    void reverse() {}
};

int main()
{
    std::cout << "Hello World!\n";
}
