// 
// CLRS 2.1.4
// Binary addition
//

#include <iostream>
#include <vector>

using namespace std;
using Binary = vector<int>;

Binary add(Binary &b1, Binary &b2)
{
    Binary sum(b1.size() + 1, 0);
    int carry = 0;

    for (auto i = b1.size() - 1; i >= 0 && i < b1.size(); --i) {
        int temp = b1[i] + b2[i] + carry;
        carry = temp / 2;
        sum[i + 1] = temp % 2;
    }
    sum[0] = carry;

    return sum;
}

int main(void)
{
    Binary b1{1, 1, 1};
    Binary b2{1, 1, 1};

    Binary sum = add(b1, b2);
    for (auto &c : sum) {
        cout << c;
    }
    cout << endl;

    return 0;
}