#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct tr {
    int l, r;
    ll sum;
} t[812345];
int n, q, a, b, c, x[212345];
void bringup(int u) { t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum; }
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) {
        t[u].sum = x[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    bringup(u);
}
void change(int u, int idx, int val) {
    if (t[u].l == t[u].r) {
        t[u].sum = val;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (idx <= mid)
        change(u << 1, idx, val);
    else
        change(u << 1 | 1, idx, val);
    bringup(u);
}
ll query(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) return t[u].sum;
    int mid = t[u].l + t[u].r >> 1;
    ll res  = 0;
    if (mid >= l) res = query(u << 1, l, r);
    if (mid < r) res += query(u << 1 | 1, l, r);
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
            printf("%lld\n", query(1, b, c));
    }
}

