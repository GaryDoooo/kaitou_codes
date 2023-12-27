#include <bits/stdc++.h>
using namespace std;
#define N 112345
#define M 212345
int n, m, u, v, e[M * 2], d[N], p[N], f[N], e_cnt, in_degree[N], tail, qq[N];
queue<int> q;

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        e[++e_cnt] = p[u];
        e[++e_cnt] = v;
        p[u]       = e_cnt;
        in_degree[v]++;
    }
    memset(d, 128, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; i++)
        if (in_degree[i] == 0) q.push(i);
    while (q.size()) {
        u = q.front();
        q.pop();
        for (int i = p[u]; i; i = e[i]) {
            v = e[i--];
            if (d[v] <= d[u]) {
                d[v] = d[u] + 1;
                f[v] = u;
            }
            if (--in_degree[v] == 0) q.push(v);
        }
    }
    if (d[n] <= 0)
        printf("IMPOSSIBLE");
    else {
        u    = n;
        tail = 0;
        while (u) {
            qq[++tail] = u;
            u          = f[u];
        }
        printf("%d\n", tail);
        while (tail) printf("%d ", qq[tail--]);
    }
}
