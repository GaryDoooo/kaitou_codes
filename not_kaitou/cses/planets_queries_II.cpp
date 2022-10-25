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

int count(int from, int goal) {
    if (a[from].on_cycle == a[goal].on_cycle and a[from].on_cycle) {
        if (a[from].order <= a[goal].order)
            return a[goal].order - a[from].order;
        else
            return a[goal].order + premt[a[from].on_cycle] - a[from].order;
    } else if (a[from].root == a[goal].root and a[from].root) {
        if (a[from].order <= a[goal].order)
            return a[goal].order - a[from].order;
        else
            return 1e9;
    } else if (a[from].on_cycle)
        return 1e9;
    else if (a[from].root) {
        return len[a[from].root] - a[from].order + 1 +
               count(nxt[a[from].root], goal);
    } else {
        printf("error from %d to %d\n", from, goal);
        printf("from %d %d %d %d goal %d %d %d %d\n", a[from].on_cycle,
               a[from].order, a[from].root, nxt[a[from].root], a[goal].on_cycle,
               a[goal].order, a[goal].root, nxt[a[goal].root]);
    }
    return 1e9;
}

int main() {
    scanf("%d%d", &n, &m);
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
    while (m--) {
        scanf("%d%d", &u, &v);
        int res = count(u, v);
        if (res >= 1e8)
            puts("-1");
        else
            printf("%d\n", res);
    }
}
