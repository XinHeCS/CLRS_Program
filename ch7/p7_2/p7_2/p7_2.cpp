//
// CLRS 7.2
// partition with same elements
// version: 1.0.0
//
#include <iostream>
#include <vector>
#include <tuple>

using Array = std::vector<int>;
using Index = int;
using RetTuple = std::tuple<Index, Index>;

RetTuple partition(Array &arr, Index s, Index e)
{
	int key = arr[e];
	Index i = s;
	Index p = s;

	for (Index j = s; j < e; ++j) {
		if (arr[j] < key) {
			using std::swap;
			swap(arr[p], arr[j]);
			swap(arr[i++], arr[p++]);
		}
		else if (arr[j] == key) {
			using std::swap;
			swap(arr[p++], arr[j]);
		}
	}

	using std::swap;
	swap(arr[e], arr[p]);

	return std::make_tuple(i, p);
}

void quickSort(Array &arr, Index s, Index e)
{
	if (s < e) {
		auto ret = partition(arr, s, e);
		quickSort(arr, s, std::get<0>(ret) - 1);
		quickSort(arr, std::get<1>(ret) + 1, e);
	}
}

int main()
{
	Array arr{ 4, 6, 4, 7, 6, 2, 8, 9, 1, 5, 4, 3 };
	//Array arr{ 1, 2, 3, 4, 5 };

	//for (auto i = 0; i < 10000; ++i) {
	//	arr.push_back(10);
	//}

	//auto ret = partition(arr, 0, arr.size() - 1);
	//std::cout << std::get<0>(ret) << ' ' << std::get<1>(ret) << std::endl;
	quickSort(arr, 0, arr.size() - 1);

	for (auto &item : arr) {
		std::cout << item << ' ';
	}
	std::cout << std::endl;

	return 0;
}