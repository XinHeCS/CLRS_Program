#include "MinHeap.h"

using namespace std;

MinHeap::MinHeap(const Array& vec) : 
    _parr(make_shared<Array>(vec)),
    _heapSize(vec.size())
{
    // Insert placeholdor element
    (*_parr).insert((*_parr).begin(), -1);
    buildHeap();
}

/**
*  return the old key
*/
int MinHeap::decreaseKey(Index i, int key)
{
    if ((*_parr)[i] < key) {
        cout << "The key is bigger than original value" << endl;
        return -1;
    }

    if (i > _heapSize && i <= 0) {
        throw out_of_range("Heap out of range!");
    }

    int oldKey = (*_parr)[i];
    while (i > 1 && key < (*_parr)[parent(i)]) {
        (*_parr)[i] = (*_parr)[parent(i)];
        i = parent(i);
    }
    (*_parr)[i] = key;

    return oldKey;
}

/**
* return the erased key
*/
int MinHeap::erase(Index i)
{
    if (i > _heapSize && i <= 0) {
        throw out_of_range("Heap out of range!");
    }

    int oldKey = (*_parr)[i];
    using std::swap;
    swap((*_parr)[i], (*_parr)[_heapSize]);
    --_heapSize;
    minHeapify(i);

    return oldKey;
}

void MinHeap::insert(int key)
{
    (*_parr).insert((*_parr).end(), key);
    ++_heapSize;
    decreaseKey(_heapSize, key);
}

int MinHeap::extractMin()
{
    int max = (*_parr)[1];
    (*_parr)[1] = (*_parr)[_heapSize];
    --_heapSize;
    minHeapify(1);

    return max;
}

void MinHeap::printHeap() const
{
    for (Index i = 1; i <= _heapSize; ++i) {
        cout << (*_parr)[i] << ' ';
    }
    cout << endl;
}

void MinHeap::minHeapify(Index i)
{
    Index left, right, smallest;

    while (true) {
        left = leftChild(i);
        right = rightChild(i);

        smallest = i;
        if (left <= _heapSize && (*_parr)[i] > (*_parr)[left]) {
            smallest = left;            
        }
        if (right <= _heapSize && (*_parr)[smallest] > (*_parr)[right]) {
            smallest = right;
        }

        if (smallest != i) {        
            using std::swap;
            swap((*_parr)[i], (*_parr)[smallest]);
            i = smallest;
        }
        else {            
            break;
        }
    }
}

void MinHeap::buildHeap()
{
    for (auto i = _heapSize / 2; i >= 1; --i) {
        minHeapify(i);
    }
}