#include <iostream>
#include <vector>

class MaxHeap {
    int _size{};
    std::vector<int> vect = { -1 };

    int parent(int i) { return i >> 1; }; // i / 2
    int left(int i) { return i << 1; }; // i * 2
    int right(int i) { return (i << 1) + 1; }; // i * 2 + 1

public:
    bool isEMpty() const { return _size == 0; };
    int getMax() const { return vect[1]; };
    void insertItem(int value);
    void shiftUp(int i);
    void
};

int main()
{
    std::cout << "Hello World!\n";
}