#include <stdio.h>
#define N 112345
#define M 212345
int n, m, u, v, e[M * 2], d[N], p[N], f[N], e_cnt, in_q[N], q[M], head = 1,
                                                                  tail;
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        e[++e_cnt] = p[u];
        e[++e_cnt] = v;
        p[u]       = e_cnt;
    }
    q[++tail] = 1;
    while (head <= tail) {
        u       = q[head++];
        in_q[u] = 0;
        for (int i = p[u]; i; i = e[i]) {
            v = e[i--];
            if (d[v] < d[u] + 1) {
                d[v] = d[u] + 1;
                f[v] = u;
                if (!in_q[v]) {
                    q[++tail] = v;
                    in_q[v]   = 1;
                }
            }
        }
    }
    if (d[n] == 0)
        printf("IMPOSSIBLE");
    else {
        u    = n;
        tail = 0;
        while (u) {
            q[++tail] = u;
            u         = f[u];
        }
        printf("%d\n", tail);
        while (tail) printf("%d ", q[tail--]);
    }
}
