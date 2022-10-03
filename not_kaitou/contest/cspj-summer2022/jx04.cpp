#include <bits/stdc++.h>
using namespace std;
int const mod = 1e9 + 7;
int cnt[1005][1005], step[1005][1005];
int main() {
    cnt[1][1] = 1;
    for (register int y = 2; y <= 1000; y++)
        for (register int x = 1; x <= 1000; x++)
            cnt[y][x] = (cnt[y - 1][x] + cnt[y][x - 1]) % mod;
    for (register int y = 1; y <= 1000; y++) {
        int passed = 0;
        for (register int x = 1; x <= 1000; x++) {
            passed     = (passed + cnt[y][x]) % mod;
            step[y][x] = (passed + step[y][x - 1]) % mod;
        }
    }
    int t, n, a;
    scanf("%d", &t);
    while (t--) {
        int res = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            res = (res + step[i][a]) % mod;
        }
        printf("%d\n", res);
    }
}
