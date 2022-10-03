#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    int l = 1000;
    int n = 1000;
    vector<int> p{1};
    for (int i = 1; i < n; i++) {
        p.push_back(rand() % l + 1 + p.back());
    }
    cout << n << endl;
    for (int i : p) cout << i << " ";
    cout << endl;
    cout << l << endl;
    cout << 10000 << endl;
    for (int i = 0; i < 10000; i++) {
        int a, b;
        do {
            a = rand() % 1000 + 1;
            b = rand() % 1000 + 1;
        } while (a == b);
        cout << a << " " << b << endl;
    }
}
