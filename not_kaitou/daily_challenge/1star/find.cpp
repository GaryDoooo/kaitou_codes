#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k;
    cin >> k;
    auto res = find(a.begin(), a.end(), k);
    cout << (res == a.end() ? -1 : res - a.begin() + 1);
}
