#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;

bool ok(int n) {
    int a [] = { -1, 4, 3, 1, 2, 3, 4, 5, 3, 0, 0, 0, 0};
    sort(a, a + 9);
    return (n >= 9 or a[n] > 8);
}

int main() {
    // int a [] = { -1, 4, 3, 1, 2, 3, 4, 5, 3, 0, 0, 0, 0};
    // vector<int> b = {0, 4, 3, 1, 2, 3, 4, 5, 6};
    int k = -1;
    int n = 9;
    for (int j = n / 2; j >= 1; j /= 2) {
        while (!ok(k + j)) k += j;
    }
    cout << k + 1 << endl;
    // cout << *(a + 14) << endl;
    // vector<int> b(a, a + 9);
//     auto k = lower_bound(a, a + 7, 3);
//     auto p = upper_bound(begin(b), end(b), 3);
    // for (auto i : b) cout << i << " ";
    // cout << endl;
//     cout << *a << *(a + 1) << a[1] << endl;
//     cout << k << " " << a << " " << k - a << endl;
//     cout << p - begin(b) << endl;
}