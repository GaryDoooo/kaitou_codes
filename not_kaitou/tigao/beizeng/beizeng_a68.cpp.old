#include <bits/stdc++.h>
using namespace std;
int n, m, f[100005][20], s, e;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> f[i][0];
    for (int k = 1, j = 1; k <= n; k <<= 1, j++) {
        for (int i = 0; i + k < n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + k][j - 1]);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        int k = trunc(log2(e - s + 1));
        cout << max(f[s - 1][k], f[e - (1 << k)][k]) << endl;
    }
}
