#include <bits/stdc++.h>
using namespace std;
int n, t, a, b, f[212345][20];
int main() {
    scanf("%d%d", &n, &t);
    // memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    for (int j = 1, k = 1; k < n; j++, k <<= 1)
        for (int i = 1; i + k <= n; i++)
            f[i][j] = min(f[i][j - 1], f[i + k][j - 1]);
    // cout << "done" << endl;
    while (t--) {
        scanf("%d%d", &a, &b);
        // if (a == b) {
        //     printf("%d\n", f[a][0]);
        //     continue;
        // }
        int k = trunc(log2(b - a + 1));
        printf("%d\n", min(f[a][k], f[b - (1 << k) + 1][k]));
    }
}
