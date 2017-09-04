//
// CLRS 6.5.9
// k-merge in O(nlgk)
//
#include "MinHeap.h"
#include <map>
#include <climits>

using namespace std;
using Matrix = vector<vector<int>>;
using Pos = Matrix::size_type;

multimap<int, Pos>
initialize(MinHeap &heap, Matrix &m)
{
    multimap<int, Pos> ret;
    Array temp;

    for (Pos i = 0; i < m.size(); ++i) {
        ret.insert({m[i][0], i});
        temp.push_back(m[i][0]);
    }
    heap = temp;

    return ret;
}

int getNext(int key, multimap<int, Pos> &record, Matrix &m)
{
    auto query = record.lower_bound(key);

    auto resultIter = 
        m[query->second].erase(m[query->second].begin());
    if (resultIter != m[query->second].end()) {
        int nextValue = m[query->second][0];
        record.erase(query);
        record.insert({nextValue, query->second});
    
        return nextValue;
    }

    return INT_MIN;
}

Array kMerge(Matrix &m)
{
    Array ret;
    MinHeap heap;
    multimap<int, Pos> record = initialize(heap, m);

    int curTop = heap.extractMin();
    while (curTop != INT_MIN) {
        ret.push_back(curTop);
        int next = getNext(curTop, record, m);
        if (next != INT_MIN) {
            heap.insert(next);
        }

        curTop = heap.extractMin();
    }

    return ret;
}

int main()
{
    Matrix m{
        {1, 2, 3, 4, 5, 21, 22, 23, 24},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 25, 25, 26, 27},
        {16, 17, 18, 19, 20}
    };

    Array result = kMerge(m);

    for (auto &item : result) {
        cout << item << ' ';
    }
    cout << endl;

    return 0;
}
