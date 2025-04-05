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

    void addFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
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
            newNode->prev = tail;
            tail = newNode;
        }
        listLength++;
    }

    void addAt(int value, int position) {
        if (position < 0 || position > listLength) {
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

        Node* newNode = new Node(value);
        Node* current = head;

        for (int i = 0; i < position; i++) {
            current = current->next;
        }

        Node* previous = current->prev;

        newNode->next = current;
        newNode->prev = previous;
        previous->next = newNode;
        current->prev = newNode;

        listLength++;
    }

    Node* findNode(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }

        return nullptr; // not found
    }

    int findIndex(int value) {
        Node* current = head;
        int index = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    void insertAfterValue(int value, int targetValue) {
        Node* targetNode = findNode(targetValue);
        if (targetNode == nullptr) {
            std::cout << "Target value not found.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = targetNode->next;
        newNode->prev = targetNode;

        if (targetNode->next != nullptr) {
            targetNode->next->prev = newNode;
        }
        else {
            tail = newNode; // update tail if inserted at end
        }

        targetNode->next = newNode;
        listLength++;
    }

    void insertBeforeValue(int value, int targetValue) {
        Node* targetNode = findNode(targetValue);
        if (targetNode == nullptr) {
            std::cout << "Target value not found.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = targetNode;
        newNode->prev = targetNode->prev;

        if (targetNode->prev != nullptr) {
            targetNode->prev->next = newNode;
        }
        else {
            head = newNode; // update head if inserted at front
        }

        targetNode->prev = newNode;
        listLength++;
    }

    void replaceData(int value, int position) {
        if (position < 0 || position >= listLength) {
            std::cout << "Invalid position\n";
            return;
        }

        Node* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        current->data = value;
    }

    void switchValue(int position1, int position2) {
        if (position1 < 0 || position1 >= listLength || position2 < 0 || position2 >= listLength) {
            std::cout << "Invalid position(s)\n";
            return;
        }

        if (position1 == position2) {
            return;
        } 

        Node* node1 = head;
        Node* node2 = head;

        for (int i = 0; i < position1; ++i) {
            node1 = node1->next;
        }
        
        for (int i = 0; i < position2; ++i) {
            node2 = node2->next;
        }
        std::swap(node1->data, node2->data);
    }

    void deleteFront() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
          
        delete temp;
        listLength--;
    }

    void deleteEnd() {
        if (tail == nullptr) {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        }
            
        else {
            head = nullptr;
        }
          
        delete temp;
        listLength--;
    }

    void deleteAt(int position) {
        if (position < 0 || position >= listLength) {
            std::cout << "Invalid position\n";
            return;
        }

        if (position == 0) {
            deleteFront();
            return;
        }

        if (position == listLength - 1) {
            deleteEnd();
            return;
        }

        Node* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        listLength--;
    }

    void deleteValue() {}
    
    void printForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
    void printBackward() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "NULL\n";
    }

    bool isEmpty() {
        return head == nullptr;
    }

    bool contains(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        listLength = 0;
    }

};

int main() {
    doubleLinkedList list;

    std::cout << "Initial list (should be empty): ";
    list.printForward();

    std::cout << "\nAdding elements\n";
    list.addFront(10);
    list.addEnd(20);
    list.addFront(5);
    list.addEnd(25);
    list.addAt(15, 2); // Insert 15 at index 2

    std::cout << "List forward: ";
    list.printForward(); // 5 <-> 10 <-> 15 <-> 20 <-> 25 <-> NULL

    std::cout << "List backward: ";
    list.printBackward(); // 25 <-> 20 <-> 15 <-> 10 <-> 5 <-> NULL

    std::cout << "\nFind tests\n";
    std::cout << "Index of 15: " << list.findIndex(15) << "\n";
    std::cout << "Contains 20? " << (list.contains(20) ? "Yes" : "No") << "\n";

    std::cout << "\nInserting before/after\n";
    list.insertAfterValue(18, 15);  // After 15
    list.insertBeforeValue(8, 10);  // Before 10
    list.printForward(); // 5 <-> 8 <-> 10 <-> 15 <-> 18 <-> 20 <-> 25

    std::cout << "\nReplace & Switch\n";
    list.replaceData(999, 3); // replace index 3 (15) with 999
    list.switchValue(1, 5);   // switch 8 with 20
    list.printForward();      // 5 <-> 20 <-> 10 <-> 999 <-> 18 <-> 8 <-> 25

    std::cout << "\nDeleting nodes\n";
    list.deleteFront();  // delete 5
    list.deleteEnd();    // delete 25
    list.deleteAt(2);    // delete 999
    list.printForward(); // 20 <-> 10 <-> 18 <-> 8

    std::cout << "\nReversing list\n";
    list.reverse();
    list.printForward(); // 8 <-> 18 <-> 10 <-> 20

    std::cout << "\nClearing\n";
    list.clear();
    std::cout << "List after clearing: ";
    list.printForward(); // Should just print "NULL"
    std::cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}

