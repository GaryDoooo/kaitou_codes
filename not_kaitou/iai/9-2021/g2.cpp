#include <bits/stdc++.h>
using namespace std;
int n, m, a_n = 0, b_n = 0, n_mask;
vector<int> a(200000);
vector<int> b(200000);
void gen_a_dfs(int i, int x) {
    if (i == n) a[a_n++] = x;
    if (i >= n) return;
    gen_a_dfs(i + 1, x << 1);
    gen_a_dfs(i + 2, (x << 2) | 3);
}
int dfs(int y, int mask) {
    if (y == m) {
        return ((~mask) & n_mask) == 0;
    }
    int res = 0;
    for (int i = 0; i < a_n; i++) {
        int t   = ((~(a[i] ^ mask)) & n_mask) | mask;
        bool OK = true;
        for (int j = 0; j < n - 2; j++) {
            if ((t & (n_mask - 3)) == 0) {
                OK = false;
                break;
            }
            t = t >> 1;
        }
        if (!OK) continue;
        int new_mask = ((~(a[i] ^ mask)) & n_mask) | a[i];
        res += dfs(y + 1, new_mask);
    }
    return res;
}
int main() {
    cin >> n >> m;
    if (n > m) swap(n, m);
    gen_a_dfs(0, 0);
    n_mask  = (1 << n) - 1;
    int res = 0;
    for (int i = 0; i < a_n; i++) {
        res += dfs(1, a[i]);
    }
    // int t = ((~(10 ^ 3)) & 15) | 3;
    // cout << t << endl;
    // cout << a_n << endl;
    cout << res << endl;
}
