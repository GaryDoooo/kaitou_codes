#include <bits/stdc++.h>
using namespace std;
int a[100005], n, m, s, e, f[100005];
map<int, int> available;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        available.clear();
        int j;
        for (j = 0; j + i <= n; j++) {
            if (available[a[j + i]]) break;
            available[a[j + i]] = 1;
        }
        // cout << i << ":" << a[i] << " ";
        // for (auto item : available)
        //     cout << item.first << ">" << item.second << " ";
        // cout << endl;
        f[i] = j;
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << endl;
    // cout << endl;
    // cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s >> e;
        int res = 0;
        for (int j = s; j <= e; j++) res = max(res, min(f[j], e - j + 1));
        cout << s << " " << e << " " << res << endl;
    }
}

