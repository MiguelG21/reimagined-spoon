#include <iostream>
#include <vector>

class MaxHeap {
    int _size{};
    std::vector<int> vect = { -1 };

    int parent(int i) { return i >> 1; }; // i / 2
    int left(int i) { return i << 1; }; // i * 2
    int right(int i) { return (i << 1) + 1; }; // i * 2 + 1

public:
    bool isEmpty() const { return _size == 0; };
    int getMax() const {
        if (_size == 0) throw std::out_of_range("Heap is empty!");
        return vect[1];
    }
    void insertItem(int value);
    void shiftUp(int i);
    int extractMax();
    void shiftDown(int i);
    void deleteItem(int val);
};

void MaxHeap::shiftUp(int i) {
    if (i > _size) return;
    if(i == 1) return;
    if (vect[i] > vect[parent(i)]) {
        std::swap(vect[parent(i)], vect[i]);
    }
    shiftUp(parent(i));
}

void MaxHeap::insertItem(int val) {
    if (_size + 1 >= vect.size()) {
        vect.push_back(0);
    }
    vect[++_size] = val;
    shiftUp(_size);
    return;
}

void MaxHeap::shiftDown(int i) {
    if (i > _size) return;
    int swapId = i;
    if (left(i) <= _size && vect[i] < vect[left(i)]) {
        swapId = left(i);
    }
    if (right(i) <= _size && vect[swapId] < vect[right(i)]) {
        swapId = right(i);
    }
    if(swapId != i){
        std::swap(vect[i], vect[swapId]);
    shiftDown(swapId);
    }
    return;
}

int MaxHeap::extractMax() {
    int maxNum = vect[1];
    std::swap(vect[1], vect[_size--]);
    shiftDown(1);
        return maxNum;
}

void MaxHeap::deleteItem(int val) {
    int indexToDelete = -1;
    for (int i = 1; i <= _size; ++i) {
        if (vect[i] == val) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        std::cout << "Value not found in heap." << std::endl;
        return;
    }

    std::swap(vect[indexToDelete], vect[_size]);
    _size--;

    shiftDown(indexToDelete);
    shiftUp(indexToDelete);
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