//
// CLRS 6.2.5
// heap sort
// version: 1.0.0
// 
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
using Index = vector<int>::size_type;
using Array = vector<int>;

class HeapSort 
{
public:
    HeapSort() = default;
    explicit HeapSort(const Array &vec) :
        _pvec(make_shared<Array>(vec)), _heapSize(vec.size()) 
    // Add a placeholdor element to let the array
    // start at index 1
    { (*_pvec).insert((*_pvec).begin(), -1); }

    int top() const { return (*_pvec)[0]; }

    void test();
    
private:
    shared_ptr<Array> _pvec;
    Index _heapSize = 0;

    Index parent(Index i) const { return i >>= 1; }
    Index leftChild(Index i) const { return i <<= 1; }
    Index rightChild(Index i) const { return i = (i << 1) + 1; }

    void downFlow(Index i);
    void buildHeap();
    void doSort();
};

void HeapSort::downFlow(Index i)
{
    Index l;
    Index r;
    Index largest;

    while (true) {
        l = leftChild(i);
        r = rightChild(i);
        largest = i;

        if (l <= _heapSize && (*_pvec)[i] < (*_pvec)[l]) {
            largest = l;
        }
        if (r <= _heapSize && (*_pvec)[largest] < (*_pvec)[r]) {
            largest = r;
        }

        if (largest != i) {
            using std::swap;
            swap((*_pvec)[i], (*_pvec)[largest]);
            i = largest;
        }
        else {
            break;
        }
    }
}

void HeapSort::buildHeap()
{
    for (auto i = _heapSize / 2; i >= 1; --i) {
        downFlow(i);
    }
}

void HeapSort::doSort()
{
    buildHeap();
    for (auto i = _heapSize; i >= 2; --i) {
        using std::swap;
        swap((*_pvec)[i], (*_pvec)[1]);
        --_heapSize;
        downFlow(1);
    }
    // Remove the placeholdor element
    (*_pvec).erase((*_pvec).begin());
}

void HeapSort::test()
{
    doSort();

    for (auto &item : *_pvec) {
        cout << item << ' ';
    }
    cout << endl;
}

int main()
{
    Array arr{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    HeapSort sort(arr);

    sort.test();

    return 0;
}

