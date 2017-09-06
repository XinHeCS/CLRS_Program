#include "kHeap.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int kHeap::extractTop()
{
	int oldKey = (*_pvec)[1];
	using std::swap;
	swap((*_pvec)[1], (*_pvec)[_heapsize]);
	--_heapsize;
	maxKHeapify(1);

	return oldKey;
}

void kHeap::insert(int key)
{
	// since we use lazy erase here,
	// so we must assure that the size of the heap
	// is smaller than the vector *_pvec
	if ((*_pvec).size() <= _heapsize + 1) {
		(*_pvec).push_back(key);
		++_heapsize;
	}
	else {
		++_heapsize;
		(*_pvec)[_heapsize] = key;
	}

	increaseKey(_heapsize, key);
}

void kHeap::increaseKey(Index i, int key)
{
	if (key < (*_pvec)[i]) {
		throw runtime_error("Key must larger than original value");
	}

	while (i > 1 && (*_pvec)[parent(i)] < key) {
		(*_pvec)[i] = (*_pvec)[parent(i)];
		i = parent(i);
	}
	(*_pvec)[i] = key;
}

void kHeap::display() const
{
	for (Index i = 1; i <= _heapsize; ++i) {
		cout << (*_pvec)[i] << ' ';
	}
	cout << endl;
}

void kHeap::maxKHeapify(Index i)
{
	Index largest;

	while (true) {
		largest = i;

		largest = getMaxChild(i);

		if (largest != i) {
			using std::swap;
			swap((*_pvec)[largest], (*_pvec)[i]);
			i = largest;
		}
		else {
			break;
		}
	}
}

void kHeap::buildHeap()
{
	for (Index i = parent(_heapsize); i >= 1; --i) {
		maxKHeapify(i);
	}
}

Index kHeap::getMaxChild(Index i)
{
	Index maxChild = i;
	for (Index child = kthChild(i, 1); 
		child <= _heapsize && child <= kthChild(i, _k); ++child) {
		if ((*_pvec)[maxChild] < (*_pvec)[child]) {
			maxChild = child;
		}
	}

	return maxChild;
}
