//
// CLRS 6.5.4
// Min heap
// version 1.0.0
//
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "MinHeap.h"

using namespace std;

int main()
{
    MinHeap heap({16, 4, 10, 14, 7, 9, 3, 2, 8, 1});

    heap.printHeap();
    heap.extractMin();
    heap.printHeap();
    heap.insert(1);
    heap.printHeap();
    heap.decreaseKey(8, 6);
    heap.printHeap();
    heap.erase(1);
    heap.printHeap();

    return 0;
}