//
// Merge Sort
//

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

int main()
{
    Array arr{3, 41, 52, 26, 38, 57, 9, 49};

    for (auto &item : arr) {
        cout << item << ' ';
    }
    cout << endl;
    mergeSort(arr, 0, arr.size() / 2);
    for (auto &item : arr) {
        cout << item << ' ';
    }
    cout << endl;

    return 0;
}

