#include <bits/stdc++.h>
using namespace std;
struct tr {
    int l, r, v;
} t[812345];
int a[212345], n, l, r, m;
void bringup(int u) { t[u].v = t[u << 1].v ^ t[u << 1 | 1].v; }
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) {
        t[u].v = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    bringup(u);
}
int q(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1;
    int res = 0;
    if (mid >= l) res = q(u << 1, l, r);
    if (mid < r) res = res ^ q(u << 1 | 1, l, r);
    return res;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    while (m--) {
        scanf("%d%d\n", &l, &r);
        printf("%d\n", q(1, l, r));
    }
}
