#include <iostream>
#include <vector>

class MaxHeap {
    std::vector<int> vect = { -1 };

    int parent(int i) { return i >> 1; }; // i / 2
    int left(int i) { return i << 1; }; // i * 2
    int right(int i) { return (i << 1) + 1; }; // i * 2 + 1

public:
    int size() const { return vect.size() - 1; }
    bool isEmpty() const { return size() == 0; }
    int getMax() const {
        if (isEmpty()) throw std::out_of_range("Heap is empty!");
        return vect[1];
    }
    void insertItem(int value);
    void shiftUp(int i);
    int extractMax();
    void shiftDown(int i);
    void deleteItem(int val);
    void heapify(const std::vector<int>& data);
    void printHeap() const;
};

void MaxHeap::shiftUp(int i) {
    if (i == 1) return;  // No need to move root
    if (vect[i] > vect[parent(i)]) {
        std::swap(vect[parent(i)], vect[i]);
        shiftUp(parent(i));  // Recurse upwards
    }
}


void MaxHeap::insertItem(int val) {
    vect.push_back(val);
    shiftUp(size());
}

void MaxHeap::shiftDown(int i) {
    int swapId = i;
    int leftChild = left(i);
    int rightChild = right(i);

    if (leftChild <= size() && vect[i] < vect[leftChild]) {
        swapId = leftChild;
    }
    if (rightChild <= size() && vect[swapId] < vect[rightChild]) {
        swapId = rightChild;
    }

    if (swapId != i) {
        std::swap(vect[i], vect[swapId]);
        shiftDown(swapId);  // Recurse down
    }
}

int MaxHeap::extractMax() {
    if (isEmpty()) throw std::out_of_range("Heap is empty!");

    int maxVal = vect[1];
    std::swap(vect[1], vect.back());
    vect.pop_back(); // Remove last element
    shiftDown(1);
    return maxVal;
}


void MaxHeap::deleteItem(int val) {
    int index = -1;
    for (int i = 1; i < vect.size(); ++i) {
        if (vect[i] == val) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Value not found in heap." << std::endl;
        return;
    }

    std::swap(vect[index], vect.back());
    vect.pop_back();

    shiftDown(index);
    shiftUp(index);
}

void MaxHeap::heapify(const std::vector<int>& data) {
    vect = { -1 }; // Preserve 1-based indexing
    vect.insert(vect.end(), data.begin(), data.end());

    for (int i = size() / 2; i >= 1; --i) {
        shiftDown(i);
    }
}


void MaxHeap::printHeap() const {
    std::cout << "Heap: ";
    for (int i = 1; i < vect.size(); ++i) {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

class MinHeap {
    std::vector<int> vect = { -1 };

    int parent(int i) { return i >> 1; }; // i / 2
    int left(int i) { return i << 1; }; // i * 2
    int right(int i) { return (i << 1) + 1; }; // i * 2 + 1

public:
    int size() const { return vect.size() - 1; }
    bool isEmpty() const { return size() == 0; }
    int getMin() const {
        if (isEmpty()) throw std::out_of_range("Heap is empty!");
        return vect[1];
    }
    void insertItem(int value);
    void shiftUp(int i);
    int extractMin();
    void shiftDown(int i);
    void deleteItem(int val);
    void heapify(const std::vector<int>& data);
    void printHeap() const;
};

void MinHeap::shiftUp(int i) {
    if (i == 1) return;
    if (vect[i] < vect[parent(i)]) {  // inverted logic
        std::swap(vect[parent(i)], vect[i]);
        shiftUp(parent(i));
    }
}

void MinHeap::insertItem(int val) {
    vect.push_back(val);
    shiftUp(size());
}

void MinHeap::shiftDown(int i) {
    int swapId = i;
    int leftChild = left(i);
    int rightChild = right(i);

    if (leftChild <= size() && vect[i] > vect[leftChild]) { // inverted logic
        swapId = leftChild;
    }
    if (rightChild <= size() && vect[swapId] > vect[rightChild]) {
        swapId = rightChild;
    }

    if (swapId != i) {
        std::swap(vect[i], vect[swapId]);
        shiftDown(swapId);  
    }
}

int MinHeap::extractMin() { //logic is still functional
    if (isEmpty()) throw std::out_of_range("Heap is empty!");

    int maxVal = vect[1];
    std::swap(vect[1], vect.back());
    vect.pop_back(); // remove last element
    shiftDown(1);
    return maxVal;
}


void MinHeap::deleteItem(int val) {
    int index = -1;
    for (int i = 1; i < vect.size(); ++i) {
        if (vect[i] == val) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Value not found in heap." << std::endl;
        return;
    }

    std::swap(vect[index], vect.back());
    vect.pop_back();

    shiftDown(index);
    shiftUp(index);
}

void MinHeap::heapify(const std::vector<int>& data) {
    vect = { -1 }; // Preserve 1-based indexing
    vect.insert(vect.end(), data.begin(), data.end());

    for (int i = size() / 2; i >= 1; --i) {
        shiftDown(i);
    }
}


void MinHeap::printHeap() const {
    std::cout << "Heap: ";
    for (int i = 1; i < vect.size(); ++i) {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    MaxHeap* PriorityQueue = new MaxHeap();

    if (PriorityQueue->isEmpty()) {
        std::cout << "Correct" << std::endl;
    }
    else {
        std::cout << "Incorrect" << std::endl;
    }

    PriorityQueue->insertItem(10);
    PriorityQueue->insertItem(20);
    PriorityQueue->insertItem(3);
    PriorityQueue->insertItem(62);
    PriorityQueue->insertItem(98);
    PriorityQueue->insertItem(25);
    
    std::cout << PriorityQueue->getMax() << std::endl;
    PriorityQueue->extractMax();
    std::cout << PriorityQueue->getMax() << std::endl;
    PriorityQueue->deleteItem(62);
    std::cout << PriorityQueue->getMax() << std::endl;


    if (PriorityQueue->isEmpty()) {
        std::cout << "Incorrect";
    }
    else {
        std::cout << "Correct";
    }
    delete PriorityQueue;

}