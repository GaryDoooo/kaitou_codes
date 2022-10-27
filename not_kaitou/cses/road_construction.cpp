#include <stdio.h>
#define N 100005
int n, m, max_res, u, v, c[N], r[N];

int get_root(int u) {
    int t = u;
    while (r[u]) u = r[u];
    if (t != u) r[t] = u;
    return u;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) c[i] = 1;
    while (m--) {
        scanf("%d%d", &u, &v);
        int ru = get_root(u), rv = get_root(v);
        if (ru == rv) {
            printf("%d %d\n", n, max_res);
        } else {
            r[rv] = ru;
            c[ru] += c[rv];
            if (c[ru] > max_res) max_res = c[ru];
            printf("%d %d\n", --n, max_res);
        }
    }
}

