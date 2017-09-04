//
// CLRS 5.1.3
// RANDOM(a, b)
//
#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

int randomMap(int b)
{
    static default_random_engine e(time(0));
    static uniform_int_distribution<unsigned> u(0, 1);

    int n = log2(b) + 1;

    while (true) {
        int r = 0;
        for (auto i = 0; i < n; ++i) {
            r = 2 * r + u(e);
        }
        if (r <= b) {
            return r;
        }
    }
}

int randomInt(int a, int b)
{
    return randomMap(b - a) + a;
}

int main()
{
    vector<int> statistic(25, 0);
    for (auto i = 0; i < 10000; ++i) {
        ++statistic[randomInt(0, 25)];
    }

    for (vector<int>::size_type item = 0; 
        item != statistic.size(); ++item) {
        cout << item << ' ';
        for (auto i = 0; i < statistic[item] / 10; ++i) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}