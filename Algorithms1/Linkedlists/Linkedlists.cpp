#include <iostream>

class Node {

public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};
};

class linkedlist { // Last added = tail;
    Node* head;
    Node* tail;
    int listLength;

public:
    linkedlist() : head(nullptr), tail(nullptr), listLength(0) {}
    ~linkedlist() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void addFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        listLength++;
    }

    void addEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        listLength++;
    }

    void addAt(int value, int position) {
        if (tail == nullptr) {
            Node* newNode = new Node(value);
            tail = newNode = head;
            return;
        }
        if (position < 0 || position > listLength - 1) {
            std::cout << "Invalid position";
            return;
        }
        if (position == 0) {
            addFront(value);
            return;
        }
        if (position == listLength) {
            addEnd(value);
            return;
        }

        Node* current = head;
        int currentPosition = 0;

        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        Node* newNode = new Node(value);
        
        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
        listLength++;
    }
    
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "Null\n";
    }

    void deleteAt(int position) {
        if (position < 0 || position >= listLength) {
            std::cout << "invalid position\n";
            return;
        }

        Node* temp;
        if (position == 0) {
            temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
        else {
            Node* prev = head;
            for (int i = 0; i < position - 1; ++i) {
                prev = prev->next;
            }
            temp = prev->next;
            prev->next = temp->next;
            if (prev->next == nullptr) {
                tail = prev;
            }
        }
        delete temp;
        listLength--;
    }

    int find(int value) {
        Node* current = head;
        int index = 0;
        bool found = false;

        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
};


int main()
{
    linkedlist myList;
    myList.addEnd(10);
    myList.addEnd(20);
    myList.addFront(5);
    myList.printList(); // Output: 5 -> 10 -> 20 -> NULL
    std::cout << "Hello World!\n";
    return 0;
}

