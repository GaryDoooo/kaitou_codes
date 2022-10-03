#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct tr {
    int l, r;
    ll k, to_add;
} t[812345];
int n, a, b, c, q, x[212345];
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) {
        t[u].k = x[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void push_down(int u) {
    if (t[u].l == t[u].r)
        t[u].k += t[u].to_add;
    else {
        t[u << 1].to_add += t[u].to_add;
        t[u << 1 | 1].to_add += t[u].to_add;
    }
    t[u].to_add = 0;
}
void add(int u, int l, int r, int k) {
    if (t[u].l >= l and t[u].r <= r) {
        t[u].to_add += k;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= l) add(u << 1, l, r, k);
    if (mid < r) add(u << 1 | 1, l, r, k);
}
ll get(int u, int idx) {
    push_down(u);
    if (t[u].l == t[u].r) return t[u].k;
    int mid = t[u].l + t[u].r >> 1;
    if (idx <= mid)
        return get(u << 1, idx);
    else
        return get(u << 1 | 1, idx);
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    build(1, 1, n);
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &a, &b, &c);
            add(1, a, b, c);
        } else {
            scanf("%d", &b);
            printf("%lld\n", get(1, b));
        }
    }
}
