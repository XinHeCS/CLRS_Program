//
// CLRS problem 6_2
// k-way-heap
//
#ifndef _KHEAP_H_
#define _KHEAP_H_

#include <iostream>
#include <vector>
#include <memory>

using Array = std::vector<int>;
using Index = std::vector<int>::size_type;

class kHeap
{
public:
	kHeap() = default;
	explicit kHeap(const Array &vec, int k = 2) :
		_pvec(std::make_shared<Array>(vec)), _heapsize(vec.size()), _k(k)
	{
		(*_pvec).insert((*_pvec).begin(), -1);
		buildHeap();
	}

	int top() const { return (*_pvec)[1]; }
	Index parent(Index i) const { return (i - 2) / _k + 1; }
	Index kthChild(Index i, Index k) const { return _k * (i - 1) + k + 1; }

	int extractTop();
	void insert(int key);
	void increaseKey(Index i, int key);
	void display() const;

private:
	std::shared_ptr<Array> _pvec = nullptr;
	Index _heapsize = 0;
	int _k = 2;

	void maxKHeapify(Index i);
	void buildHeap();
	Index getMaxChild(Index i);
};

#endif
