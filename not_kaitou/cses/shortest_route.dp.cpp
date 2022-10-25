//
// This only works for graphs without circles
//
#include <stdio.h>
#include <string.h>
#define N 100001
#define M 2 * N
int n, m, e[M * 3], p[N], e_cnt, u, v, w, working[N];
long long d[N];

long long dfs(int u) {
    if (working[u] or d[u] < 1e18) return d[u];
    long long &res = d[u];
    working[u]     = 1;
    for (int i = p[u]; i; i = e[i]) {
        int v        = e[i--];
        long long nd = dfs(v) + e[i--];
        res          = (res > nd ? nd : res);
    }
    working[u] = 0;
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        e[++e_cnt] = p[v];  // record the vector reversely
        e[++e_cnt] = w;
        e[++e_cnt] = u;
        p[v]       = e_cnt;
    }
    memset(d, 127, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; i++) printf("%lld\n", dfs(i));
}
