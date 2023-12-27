#include <stdio.h>
#define N 100005
#define M 200005
int n, m, e_cnt, p[N], r[N], u, v, s[N], s_top, vis_order[N], vis[N];
int e[M * 2], done[M * 2], ps[N];
// struct node {
//     int l, r, w;
// } a[N * 4];
//
// void build(int u, int l, int r) {
//     a[u] = {l, r};
//     if (l == r) return;
//     int mid = l + r >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
// }
//
// void push_down(int u) {
//     if (a[u].w) {
//         int mid         = a[u].l + a[u].r >> 1;
//         a[u << 1 | 1].w = a[u << 1].w = a[u].w;
//         a[u].w                        = 0;
//     }
// }
//
// void assign(int u, int x, int w) {
//     if (a[u].l == a[u].r) {
//         a[u].w = w;
//         return;
//     }
//     push_down(u);
//     int mid = a[u].l + a[u].r >> 1;
//     if (mid >= x)
//         assign(u << 1, x, w);
//     else
//         assign(u << 1 | 1, x, w);
// }
//
// int read(int u, int x) {
//     if (a[u].w) return a[u].w;
//     int mid = a[u].l + a[u].r >> 1;
//     if (mid >= x)
//         return read(u << 1, x);
//     else
//         return read(u << 1 | 1, x);
// }
//
int get_root(int u) {
    int t = u;
    while (r[u]) u = r[u];
    if (t != u) r[t] = u;
    return u;
}

void combine(int u, int v) {
    int ru = get_root(u), rv = get_root(v);
    if (ru == rv) return;
    // if (vis_order[ru] > vis_order[rv])
    r[u] = r[ru] = rv;
    // else
    // r[v] = r[rv] = ru;
}

void consolidate(int s_start, int to) {
    for (int i = s_top; i > s_start; i--) {
        if (r[s[i]] == to) {
            if (ps[i] > 0) i = ps[i] - 1;
            continue;
        }
        combine(s[i], to);
        ps[i] = s_start;
    }
}

void dfs(int u) {
    vis[u] = 1;
    // printf("%d\n", u);
    int ru = get_root(u);
    if (vis_order[ru] > 0) {
        consolidate(vis_order[ru], ru);
        return;
    }
    // assign(1,++s_top, ru);
    s[++s_top]    = ru;
    ps[s_top]     = 0;
    vis_order[ru] = s_top;
    for (int i = p[u]; i; i = e[--i]) {
        int v = e[i];
        if (done[i]) continue;
        done[i] = 1;
        dfs(v);
    }
    s_top--;
    vis_order[ru] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        e[++e_cnt] = p[u];
        e[++e_cnt] = v;
        p[u]       = e_cnt;
    }
    // build(1,1,n);
    dfs(1);
    for (int i = 1; i <= n; i++) {
        int root = get_root(i);
        // printf("%d %d\n", root, i);
        if (root != 1) {
            puts("NO");
            if (vis[root])
                printf("%d 1\n", root);
            else
                printf("1 %d\n", root);
            return 0;
        }
    }
    puts("YES");
}

