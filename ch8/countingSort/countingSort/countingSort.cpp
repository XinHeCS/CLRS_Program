//
// CLRS counting sort
// version: 1.0.0
//
#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <ctime>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;

Array countingSort(Array &arr)
{
	// find the max value of arr
	// to determine the size of C
	int k = INT_MIN;
	for (auto &item : arr) {
		if (item > k) {
			k = item;
		}
	}

	Array C(k + 1, 0);
	for (auto &item : arr) {
		++C[item];
	}

	for (Index i = 1; i < C.size(); ++i) {
		C[i] += C[i - 1];
	}

	Array B(arr.size());
	for (int i = arr.size() - 1; i >= 0; --i) {
		B[C[arr[i]] - 1] = arr[i];
		--C[arr[i]];
	}

	return B;
}

int main()
{
	static default_random_engine e(static_cast<int>(time(0)));
	static uniform_int_distribution<unsigned> u(0, 10000);

	//Array arr{ 2, 5, 3, 0, 2, 3, 0, 3, 7, 9, 10, 1, 11, 12, 13 };
	Array arr;
	for (int i = 0; i < 10000; ++i) {
		arr.push_back(u(e));
	}
	Array result = countingSort(arr);

	for (auto &item : result) {
		cout << item << ' ';
	}
	cout << endl;

	return 0;
}