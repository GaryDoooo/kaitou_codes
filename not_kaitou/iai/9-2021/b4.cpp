#include <bits/stdc++.h>
using namespace std;
int main() {
    int y, m, d, n;
    int res = 1e9;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        y     = atoi(s.substr(0, 4).c_str());
        m     = atoi(s.substr(5, 2).c_str());
        d     = atoi(s.substr(8, 2).c_str());
        int x = (y << 9) + (m << 5) + d;
        res   = min(res, x);
    }
    d = res & 31;
    m = (res >> 5) & 15;
    y = (res >> 9);
    printf("%d-%02d-%02d\n", y, m, d);
}

