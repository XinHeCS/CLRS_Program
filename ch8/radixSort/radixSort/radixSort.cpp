//
// CLRS Radix Sort
// auther: HeXin
// version: 1.0.0
//
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stdio.h>

using namespace std;
using Array = vector<int>;
using Index = int;

int getDigit(int a, Index pos)
{
	int ret = 0;
	for (auto i = 1; i <= pos; ++i) {
		ret = a % 10;
		a /= 10;
	}

	return ret;
}

void positionCountingSort(Array &arr, Index pos)
{
	Array ret(arr.size(), 0);
	Array C(10, 0);

	for (Index i = 0; i < arr.size(); ++i) {
		++C[getDigit(arr[i], pos)];
	}

	for (Index i = 1; i < C.size(); ++i) {
		C[i] += C[i - 1];
	}

	for (Index i = arr.size() - 1; i >= 0; --i) {
		ret[C[getDigit(arr[i], pos)] - 1] = arr[i];
		--C[getDigit(arr[i], pos)];
	}

	arr = ret;
}

void radixSort(Array &arr)
{
	Array ret;
	
	// find the max number of arr
	// to determine the max digits number of this array
	int max = INT_MIN;
	for (auto &item : arr) {
		if (item > max) {
			max = item;
		}
	}

	int digits = static_cast<int>(log10(max)) + 1;
	for (int i = 1; i <= digits; ++i) {
		positionCountingSort(arr, i);
	}
}

int main()
{
	Array arr{ 329, 355, 457, 456, 657, 720, 839 };

	radixSort(arr);

	for (auto &item : arr) {
		cout << item << ' ';
	}
	cout << endl;

	return 0;
}