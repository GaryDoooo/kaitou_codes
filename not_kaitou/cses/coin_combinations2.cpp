#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, x, f[1123456], c[112], d;
int main() {
    scanf("%d%d", &n, &x);
    f[0] = 1;
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j + c[i] <= x; j++) {
            f[j + c[i]] = (f[j + c[i]] + f[j]) % MOD;
            // if (d = j - c[i], d >= 0) f[j] = (f[j] + f[d]) % MOD;
        }
    // for (int i = 1; i <= x; i++) cout << f[i] << " ";
    cout << f[x] << endl;
}
