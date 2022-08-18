#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int n, p, f[2005][2005];
set<int> d[2005];
int main() {
    cin >> n >> p;
    for (int i = 1; i <= sqrt(n); i++) {
        for (int j = i * i, k = i; j <= n; j += i, k++) {
            d[j].insert(i);
            d[j].insert(k);
        }
    }
    for (int i = 1; i <= n; i++) f[1][i] = 1;
    for (int j = 2; j <= p; j++)
        for (int i = 1; i <= n; i++)
            for (int k : d[i]) f[j][i] = (f[j][i] + f[j - 1][k]) % MOD;
    int res = 0;
    for (int i = 1; i <= n; i++) res = (res + f[p][i]) % MOD;
    cout << res;
}
