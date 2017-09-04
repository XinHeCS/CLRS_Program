#include <iostream>
#include <vector>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;

void merge(Array &arr, Index p, Index q, Index r)
{
    Array left;
    for (auto i = p; i != q + 1; ++i) {
        left.push_back(arr[i]);
    }
    Array right;
    for (auto i = q + 1; i != r + 1; ++i) {
        right.push_back(arr[i]);
    }

    Index i = 0, j = 0;
    Index k = p;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            ++i;
        }
        else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

void mergeSort(Array &arr, Index p, Index r)
{
    if (p < r) {
        Index q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void twoSum(Array &arr, int sum)
{
    mergeSort(arr, 0, arr.size() - 1);
    Index i = 0, j = arr.size() - 1;
    while (i < j) {
        if (arr[i] + arr[j] < sum) {
            ++i;
        }
        else if (arr[i] + arr[j] > sum) {
            --j;
        }
        else {
            cout <<"( " << i << ", " << j << " )" << endl;
            ++i;
            --j;
        }
    }
}

int main()
{
    Array arr{1, 2, 3, 4, 5, 6};
    twoSum(arr, 7);

    return 0;
}