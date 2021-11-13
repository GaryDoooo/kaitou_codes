#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> v;
    for (unsigned long long i = 1; i < (1ULL << n); i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) s += a[j];
        }
        v.push_back(s);
    }
    // for (int i : v) cout << i << endl;
    sort(v.begin(), v.end());
    cout << v[(1 << (n - 1)) - 1];
}
