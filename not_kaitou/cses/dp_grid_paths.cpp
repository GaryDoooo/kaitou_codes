#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, f[1002][1002], m[1002][1002];
char c[1002];
int main() {
    scanf("%d", &n);
    for (int y = 1; y <= n; y++) {
        scanf("%s\n", c);
        for (int x = 1; x <= n; x++)
            if (c[x - 1] == '*') m[x][y] = 1;
    }
    if (m[1][1]) {
        puts("0");
        return 0;
    }
    f[0][1] = 1;
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= n; x++)
            if (m[x][y] == 0) f[x][y] = (f[x - 1][y] + f[x][y - 1]) % MOD;
    cout << f[n][n] << endl;
}
