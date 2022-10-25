#include <stdio.h>
int n, m, u, v, in[112345], e[412345], p[112345], e_cnt;
int q[112345], head = 1, tail;
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        e[++e_cnt] = p[u];
        e[++e_cnt] = v;
        p[u]       = e_cnt;
        in[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q[++tail] = i;
    while (head <= tail) {
        u = q[head++];
        for (int i = p[u]; i; i = e[i]) {
            v = e[i--];
            if (--in[v] == 0) q[++tail] = v;
        }
    }
    if (tail == n)
        for (int i = 1; i <= n; i++) printf("%d ", q[i]);
    else
        printf("IMPOSSIBLE");
}
