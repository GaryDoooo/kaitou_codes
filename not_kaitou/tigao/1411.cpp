#include <bits/stdc++.h>
using namespace std;
int const MOD = 1000000007;
int n, m, k, u[201][201], f[201][201], init[201][201];
char a[1005], b[205];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s\n", a + 1);
    scanf("%s\n", b + 1);
    f[0][0] = init[0][0] = 1;
    for (register int ap = 1; ap <= n; ap++) {
        for (register int bp = min(ap, m); bp >= 1; bp--) {
            if (b[bp] == a[ap])
                for (register int c = min(bp, k); c > 0; c--) {
                    u[bp][c] = (u[bp - 1][c] + f[bp - 1][c - 1]) % MOD;
                    f[bp][c] = (f[bp][c] + u[bp][c]) % MOD;
                }
            else
                memcpy(u, init, sizeof(u));
        }
    }
    printf("%d\n", f[m][k]);
}
