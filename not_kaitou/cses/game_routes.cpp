#include <stdio.h>
#include <string.h>
#define N 100001
#define M N * 2
const int mod = 1e9 + 7;
int n, m, u, v, e[M * 2], h[N], c, d[N];

int dp(int u) {
    if (d[u] >= 0) return d[u];
    int &res = d[u];
    res      = 0;
    for (int i = h[u]; i; i = e[i]) res = (res + dp(e[i--])) % mod;
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(d, 128, sizeof(d));
    while (m--) {
        scanf("%d%d", &u, &v);
        e[++c] = h[v];
        e[++c] = u;
        h[v]   = c;
    }
    d[1] = 1;
    printf("%d\n", dp(n));
}
