#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a [] = { -1, 4, 3, 1, 2, 3, 4, 5, 3};
    // vector<int> b = {0, 4, 3, 1, 2, 3, 4, 5, 6};
    sort(a, a + 9);
    vector<int> b(a, a + 9);
    auto k = lower_bound(a, a + 7, 3);
    auto p = upper_bound(begin(b), end(b), 3);
    for (auto i : b) cout << i << " ";
    cout << endl;
    cout << *a << *(a + 1) << a[1] << endl;
    cout << k << " " << a << " " << k - a << endl;
    cout << p - begin(b) << endl;
}