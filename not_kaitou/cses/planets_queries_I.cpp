#include <stdio.h>
#define N 200005
int n, q, a, b, f[N][35];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    for (int j = 1, k = 1; k <= 1e9; j++, k <<= 1)
        for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
    while (q--) {
        scanf("%d%d", &a, &b);
        int k = 0;
        while (b) {
            if (b & 1) a = f[a][k];
            b >>= 1;
            k++;
        }
        printf("%d\n", a);
    }
}

