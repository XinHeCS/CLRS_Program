//
// CLRS problem 6_2
// k-way-heap
//
#include <iostream>
#include "kHeap.h"

using namespace std;

int main()
{
	Array vec{ 1, 2, 3, 4, 5, 6, 7, 8 };
	kHeap h(vec, 3);

	h.display();
	h.insert(9);
	h.insert(10);
	h.display();
	cout << h.extractTop() << endl;
	h.display();
	h.increaseKey(7, 15);
	h.display();

	return 0;
}