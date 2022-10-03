#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, w;//, cnt = 0;
    cin >> m >> n;
    int a[1001], a_i = 0;
    unordered_set<int> ram;
    for (int i = 0; i < n; i++) {
        cin >> w;
        if (ram.find(w) != ram.end()) { continue;}
        ram.insert(w);
        a[a_i++] = w;
        if (ram.size() > m) {
            ram.erase(a[a_i - m - 1]);
        }
    }
    cout << a_i;
}