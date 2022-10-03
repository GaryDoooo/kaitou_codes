#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, r1, r2;
    cin >> n >> k >> r1;
    int a[n], mask = (1 << (k << 1)) - 1;
    unordered_set<int> res;
    a[0] = r1 & 3;
    for (int i = 1; i < n; i++) {
        r2 = (r1 * 6807 + 2831) % 201701;
        a[i] = r2 & 3;
        r1 = r2;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    int segment = 0;
    for (int i = 0; i < k; i++) {
        segment = (segment << 2) + a[i];
    }
    res.insert(segment);
    for (int i = k; i < n; i++) {
        segment = ((segment << 2) + a[i])&mask;
        res.insert(segment);
    }
    cout << res.size();
}