//
// CLRS 6.5.4
// Min heap
// version 1.0.0
//
#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using Array = std::vector<int>;
using Index = std::vector<int>::size_type;

class MinHeap
{
public:
    MinHeap() = default;
    MinHeap(const Array &vec);

    int getMin() const { return (*_parr)[1]; }
    Index parent(Index i) const { return i >> 1; }
    Index leftChild(Index i) const { return i << 1; }
    Index rightChild(Index i) const { return (i << 1) + 1; }

    int decreaseKey(Index i, int key);
    int erase(Index i);
    void insert(int key);
    int extractMin();
    void printHeap() const;

    MinHeap &operator=(const Array &arr);

private:
    std::shared_ptr<Array> _parr = nullptr;
    Index _heapSize = 0;

    void minHeapify(Index i);
    void buildHeap();
};

#endif