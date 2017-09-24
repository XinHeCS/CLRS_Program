//
// CLRS Chapter 7
// Quick Sort
// version: 1.0.0
// 
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using Array = std::vector<int>;
//using Index = std::vector<int>::size_type;
using Index = int;

Index partition(Array &arr, Index s, Index e)
{
	int key = arr[e];	
	Index i = s;

	for (Index j = s; j < e; ++j) {
		if (arr[j] <= key) {
			using std::swap;
			swap(arr[j], arr[i]);
			++i;
		}
	}

	using std::swap;
	swap(arr[i], arr[e]);

	return i;
}

Index hoarePartition(Array &arr, Index s, Index e)
{
	int key = arr[s];
	Index i = s - 1;
	Index j = e + 1;

	while (true) {
		do
		{
			--j;
		} while (arr[j] > key);

		do
		{
			++i;
		} while (arr[i] < key);

		if (i < j) {
			using std::swap;
			swap(arr[i], arr[j]);
		}
		else {
			return j;
		}
	}
}


void quickSort(Array &arr, Index s, Index e)
{
	if (s < e) {
		//Index p = partition(arr, s, e);		
		//quickSort(arr, s, p - 1);
		//quickSort(arr, p + 1, e);

		// Hoare partition
		Index p = hoarePartition(arr, s, e);
		quickSort(arr, s, p);
		quickSort(arr, p + 1, e);
	}
}

int main()
{
	static std::default_random_engine e(static_cast<int>(time(0)));
	static std::uniform_int_distribution<unsigned> u(0, 5000);

	Array arr;

	for (auto i = 0; i < 10; ++i) {
		arr.push_back(u(e));
	}

	quickSort(arr, 0, arr.size() - 1);

	for (auto item : arr) {
		std::cout << item << ' ';
	}
	std::cout << std::endl;

	return 0;
}


