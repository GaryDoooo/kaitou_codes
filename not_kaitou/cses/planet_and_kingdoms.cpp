#include <stdio.h>
#define N 100005
int n, m, e[N * 4], p[N], done[N * 4], u, v, cnt;
int s[N], sTop, sp[N], a[N], root_cnt[N],vis[N];  //, joined[N];

int get_root(int u) {
    int t = u;
    while (a[u]) u = a[u];
    if (t != u) a[t] = u;
    return u;
}

void combine(int u, int to_root) {
    int ur = get_root(u);
    if (ur == to_root) return;
    a[u] = a[ur] = to_root;
    // joined[u] = joined[to_root] = 1;
}

main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        e[++cnt] = p[u];
        e[++cnt] = v;
        p[u]     = cnt;
    }`
}
/*
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n, m, e[2][N * 4], p[2][N], u, v, c[2], vis[2][N];
long long r[N];
set<long long> kingdoms;
main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        e[0][++c[0]] = v;
        e[0][++c[0]] = p[0][u];
        p[0][u]      = c[0];

        e[1][++c[1]] = u;
        e[1][++c[1]] = p[1][u];
        p[1][u]      = c[1];
    }
    for (int in = 0; in < 2; in++) {
        int q[N], h, t, root;
        for (int i = 1; i <= n; i++) {
            if (vis[in][i]) continue;
            root = q[h = t = 1] = i;
            while (h <= t) {
                int now = q[h++];
                if (vis[in][now]) continue;
                vis[in][now] = 1;
                r[now]=(r[now]<<20)+root;
                for (
*/
