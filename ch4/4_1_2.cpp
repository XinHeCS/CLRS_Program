//
// CLRS 4.1.2
// Brute force max subarray
//
#include <vector>
#include <iostream>
#include <tuple>
#include <climits>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;
using RetTuple = tuple<Index, Index, int>;

RetTuple BFMaxSubarray(Array &arr, Index s, Index e)
{
    int maxSum = INT_MIN;
    Index left = s;
    Index right = s;
    for (auto i = s; i <= e - 1; ++i) {
        int tempSum = arr[i];
        for (auto j = i + 1; j <= e; ++j) {
            tempSum += arr[j];
            if (tempSum > maxSum) {
                maxSum = tempSum;
                left = i;
                right = j;
            }
        }
    }

    return make_tuple(left, right, maxSum);
}

int main()
{
    Array arr{1, -4, 3, -3, 6};

    RetTuple ret = BFMaxSubarray(arr, 0, arr.size() - 1);
    cout << get<0>(ret) << ' ' << get<1>(ret) << ' '
        << get<2>(ret) << endl;

    return 0;
}