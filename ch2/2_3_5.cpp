//
// Binary Search
//

#include <iostream>
#include <vector>

using namespace std;
using Array = vector<int>;
using Index = vector<int>::size_type;

Index binarySearch(Array &arr, Index s, Index e, const int &item)
{
    if (s <= e) {
        Index m = (s + e ) / 2;
        if (item < arr[m]) {
            return binarySearch(arr, s, m - 1, item);
        }
        else if (item > arr[m]) {
            return binarySearch(arr, m + 1, e, item);
        }
        else {
            return m;
        }
    }

    return arr.size();
}

int main()
{
    Array arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "5 in position " 
        << binarySearch(arr, 0, arr.size() - 1, 5) << endl;
    cout << "1 in position " 
        << binarySearch(arr, 0, arr.size() - 1, 1) << endl;
    cout << "11 in position " 
        << binarySearch(arr, 0, arr.size() - 1, 11) << endl;
    
    return 0;
}