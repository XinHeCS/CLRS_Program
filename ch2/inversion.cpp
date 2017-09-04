//
// CLRS inversion
// Calculate the number of inversions
//
#include <iostream>
#include <vector>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;

// Return the invertion number of arr[s ... e]
int merge(Array &arr, Index s, Index m, Index e)
{
    Array L;
    for (auto i = s; i <= m; ++i) {
        L.push_back(arr[i]);
    }
    Array R;
    for (auto i = m + 1; i <= e; ++i) {
        R.push_back(arr[i]);
    }

    // Merge
    int inversion = 0;
    Index i = 0, j = 0;
    Index k = s;
    while (i < L.size() && j < R.size()) {
        if (L[i] > R[j]) {
            inversion += L.size() - i;
            arr[k++] = R[j++];
        }
        else {
            arr[k++] = L[i++];
        }
    }

    while (i < L.size()) {
        arr[k++] = L[i++];
    }
    while (j < R.size()) {
        arr[k++] = R[j++];
    }

    return inversion;
}

int getInversion(Array &arr, Index s, Index e)
{
    int inversion = 0;
    if (s < e) {
        Index m = (s + e ) / 2;
        inversion += getInversion(arr, s, m);
        inversion += getInversion(arr, m + 1, e);
        inversion += merge(arr, s, m, e);
    }

    return inversion;
}

int main()
{
    Array arr{5, 4, 3, 2, 1};
    
    cout << getInversion(arr, 0, arr.size() - 1) << endl;

    return 0;
}