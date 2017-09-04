// 
// CLRS 4-1-5
// Max subarray in O(n)
//
#include <vector>
#include <iostream>
#include <tuple>
#include <climits>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;
using RetTuple = tuple<Index, Index, int>;

RetTuple maxSubarray(Array &arr, Index s, Index e)
{
    Index left = 0, right = 0;
    int maxSum = INT_MIN;
    
    int sum = 0;
    Index tempLeft = s;
    for (auto i = s; i <= e; ++i) {
        sum += arr[i];
        if (sum > maxSum) {
            maxSum = sum;
            right = i;
            left = tempLeft;
        }
        if (sum < 0) {
            sum = 0;
            tempLeft = i + 1;
        }
    }

    return make_tuple(left, right, maxSum);
}

int main()
{
    Array arr{1, -4, 3, -3, 4};

    RetTuple ret = maxSubarray(arr, 0, arr.size() - 1);
    cout << get<0>(ret) << ' ' << get<1>(ret) << ' '
        << get<2>(ret) << endl;

    return 0;
}