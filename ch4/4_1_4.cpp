// 
// CLRS 4-1-4
// Max subarray
//
#include <vector>
#include <iostream>
#include <tuple>
#include <climits>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;
using RetTuple = tuple<Index, Index, int>;

RetTuple maxCross(Array &arr, Index s, Index m, Index e)
{
    Index left = m;
    Index right = m + 1;

    int sum = 0;
    int leftSum = INT_MIN;
    for (auto i = m; i >= s && i < arr.size(); --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            left = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (auto i = m + 1; i <= e; ++i) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            right = i;
        }
    }

    return make_tuple(left, right, leftSum + rightSum);
}

RetTuple maxSubarray(Array &arr, Index s, Index e)
{
    // Check for positive integer
    // if no positive integer exists
    // then, just return 0
    bool hasPositive = false;
    for (auto i = s; i <= e; ++i) {
        if (arr[i] >= 0) {
            hasPositive = true;
            break;
        }
    }
    if (!hasPositive) {
        return make_tuple(s, s, 0);
    }

    if (e == s) {
        return make_tuple(s, e, arr[s]);        
    }
    else {
        auto m = (s + e) / 2;
        auto leftRet = maxSubarray(arr, s, m);
        auto rightRet = maxSubarray(arr, m + 1, e);
        auto crossRet = maxCross(arr, s, m, e);
        if (get<2>(leftRet) > get<2>(rightRet) &&
            get<2>(leftRet) > get<2>(crossRet)) {
            return leftRet;                
        }
        else if (get<2>(rightRet) > get<2>(leftRet) &&
                get<2>(rightRet) > get<2>(crossRet)) {
            return rightRet;                    
        }
        else {
            return crossRet;
        }
    }
}

int main()
{
    Array arr{-1, -4, -3, -3, -3};

    RetTuple ret = maxSubarray(arr, 0, arr.size() - 1);
    cout << get<0>(ret) << ' ' << get<1>(ret) << ' '
        << get<2>(ret) << endl;

    return 0;
}