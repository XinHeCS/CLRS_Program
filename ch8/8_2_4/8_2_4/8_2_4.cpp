// 
// CLRS 8-2-4
// Range count
// version: 1.0.0
//
#include <iostream>
#include <vector>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;

int rangeCount(Array &arr, int a, int b, int k)
{
	int count = 0;

	Array c(k, 0);

	for (auto &item : arr) {
		++c[item];
	}

	for (Index i = 1; i < c.size(); ++i) {
		c[i] += c[i - 1];
	}

	return a <= 0 ? c[b] : c[b] - c[a - 1];
}

int main()
{
	Array arr{ 2, 5, 3, 0, 2, 3, 0, 3 };

	int sum = rangeCount(arr, 2, 4, 10);
	cout << "There are " << sum << " number(s) in range " << "(" << "2" << ", " << "3" << ")" << endl;

	return 0;
}