#include <bits/stdc++.h>
using namespace std;
int n, x, a[5123], cnt;
set<pair<int, int>> s;
int main() {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[cnt]);
        if (a[cnt] >= x) continue;
        s.insert(make_pair(a[cnt], i));
        cnt++;
    }
    for (auto i : s)
        for (auto j : s) {
            if (i.second == j.second) continue;
            if (i.first + j.first >= x) break;
            int c   = x - i.first - j.first;
            auto it = s.lower_bound(make_pair(c, 0));
            if (it != s.end()) {
                if (it->first == c and it->second != i.second and
                    it->second != j.second) {
                    cout << i.second << " " << j.second << " " << it->second
                         << endl;
                    return 0;
                }
            }
        }
    cout << "IMPOSSIBLE" << endl;
}

