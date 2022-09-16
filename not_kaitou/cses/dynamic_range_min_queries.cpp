#include <bits/stdc++.h>
using namespace std;
struct tr {
    int l, r, v;
} t[812345];
int n, q, a, b, c, x[212345];
void bringup(int u) { t[u].v = min(t[u << 1].v, t[u << 1 | 1].v); }
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) {
        t[u].v = x[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    bringup(u);
}
void change(int u, int idx, int val) {
    if (t[u].l == t[u].r) {
        t[u].v = val;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (idx <= mid)
        change(u << 1, idx, val);
    else
        change(u << 1 | 1, idx, val);
    bringup(u);
}
int query(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1;
    int res = 2e9;
    if (mid >= l) res = min(res, query(u << 1, l, r));
    if (mid < r) res = min(res, query(u << 1 | 1, l, r));
    return res;
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    build(1, 1, n);
    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1)
            change(1, b, c);
        else
            printf("%d\n", query(1, b, c));
    }
}

