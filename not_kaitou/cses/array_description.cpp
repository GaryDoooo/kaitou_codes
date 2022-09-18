#include <bits/stdc++.h>
using namespace std;
int const MOD = 1e9 + 7;
int n, m, x[112345];
unsigned int f[112345][105];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    if (x[0])
        f[0][x[0]] = 1;
    else
        for (int i = 1; i <= m; i++) f[0][i] = 1;
    for (int i = 1; i < n; i++) {
        if (x[i])
            f[i][x[i]] =
                (f[i - 1][x[i] - 1] + f[i - 1][x[i]] + f[i - 1][x[i] + 1]) %
                MOD;
        else
            for (int j = 1; j <= m; j++)
                f[i][j] =
                    (f[i - 1][j - 1] + f[i - 1][j] + f[i - 1][j + 1]) % MOD;
    }
    int res = 0;
    for (int i = 1; i <= m; i++) res = (res + f[n - 1][i]) % MOD;
    cout << res << endl;
}

