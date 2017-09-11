//
// CLRS 7.4
// fuzzy sort
// version: 1.0.0
//
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using Interval = pair<int, int>;
using Array = vector<Interval>;
using Index = vector<Interval>::size_type;
using RetPair = pair<int, int>;

RetPair partition(Array &arr, int s, int e)
{
	Interval key = arr[e];
	int i = s;
	int p = s;

	for (auto j = s; j < e; ++j) {
		if (arr[j].second < key.first) {
			using std::swap;
			swap(arr[j], arr[p]);
			swap(arr[p++], arr[i++]);
		}
		else if (arr[j].first <= key.second && arr[j].second >= key.first) {
			key.first = key.first >= arr[j].first ? key.first : arr[j].first;
			key.second = key.second <= arr[j].second ? key.second : arr[j].second;
			using std::swap;
			swap(arr[j], arr[p++]);
		}
	}

	using std::swap;
	swap(arr[e], arr[p]);

	return make_pair(i, p);
}

void fuzzySort(Array &arr, int s, int e)
{
	if (s < e) {
		RetPair ret = partition(arr, s, e);
		fuzzySort(arr, s, ret.first - 1);
		fuzzySort(arr, ret.second + 1, e);
	}
}

int main()
{
	Array arr{
		{1, 4}, {2, 5}, {4, 11}, {2, 7}, {9, 12}, {5, 7}, {5, 9}, {8, 11},
		{1, 2}, {1, 3}, {2, 3}, {4, 7}
	};

	fuzzySort(arr, 0, arr.size() - 1);

	for (auto &item : arr) {
		cout << "(" << item.first << ',' << item.second << ')' << ' ';
	}
	cout << endl;

	return 0;
}


