#include <stdio.h>
#define N 200001
int n, m, u, v, p[N], q[N], head = 1, tail;
int nxt[N];    // next node that the last node pointing to
int premt[N];  // Premeter of a cycle. how many nodes on one cycle.
int len[N];    // length of a line
struct node {
    int in, on_cycle, order, root;
} a[N];

int min(int x, int y) { return (x < y) ? x : y; }

int count(int from) {
    if (a[from].on_cycle) {
        return premt[a[from].on_cycle];
    } else if (a[from].root) {
        return len[a[from].root] - a[from].order + 1 + count(nxt[a[from].root]);
    } else {
        printf("error from %d \n", from);
        printf("from %d %d %d %d\n", a[from].on_cycle, a[from].order,
               a[from].root, nxt[a[from].root]);
    }
    return 1e9;
}

int main() {
    scanf("%d", &n);
    for (u = 1; u <= n; u++) {
        scanf("%d", &v);
        p[u] = v;
        a[v].in++;
    }
    for (u = 1; u <= n; u++)
        if (a[u].in == 0) {
            q[++tail]  = u;  // queue
            a[u].root  = u;  // root
            a[u].order = 1;  // order i.e.depth
        }
    while (head <= tail) {
        u = q[head++];
        v = nxt[a[u].root] = p[u];
        len[a[u].root]++;
        if (--a[v].in == 0) {
            q[++tail]  = v;
            a[v].root  = a[u].root;
            a[v].order = a[u].order + 1;
        }
    }
    for (u = 1; u <= n; u++) {
        if (a[u].in == 0) continue;
        int cycle = u, &cnt = premt[u];
        for (int i = u; a[i].in > 0; i = p[i]) {
            a[i].on_cycle = cycle;
            a[i].in       = 0;
            a[i].order    = ++cnt;
        }
    }
    for (u = 1; u <= n; u++) {
        printf("%d\n", count(u));
    }
}
