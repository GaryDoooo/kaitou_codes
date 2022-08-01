#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], f[100005][20], s, e;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> f[i][0];
    for (int k = 1, j = 1; k <= n; k <<= 1, j++) {
        cout << k << " " << j << endl;
        for (int i = 0; i + k < n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + k][j - 1]);
        }
    }
    // cout << (1 << 2) << endl;
    cin >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) cout << f[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        s--;
        e--;
        int k      = trunc(log2(e - s + 1));
        int offset = 1;
        offset <<= k;
        cout << s << " " << e << " " << k << " " << offset << endl;
        // cout << k << " " << offset << endl;
        // cout << max(f[s][k], f[e - offset + 1][k]) << endl;
    }
}
