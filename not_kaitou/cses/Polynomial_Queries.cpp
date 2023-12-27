#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r;
    long long s, add;
};

int n, q, b, a[212345], c, d;
node t[812345];

void add(int u, int l, long long offset) {
    t[u].add += (long long)(t[u].l - l) + offset;
    // t[u].add_e += t[u].r - l + 1 + offset;
}

void push_down(int u) {
    if (t[u].add == 0) return;
    long long size = t[u].r - t[u].l + 1;
    t[u].s += (t[u].add * 2 + size - 1) * size / 2;
    if (t[u].l < t[u].r) {
        add(u << 1, t[u].l, t[u].add);
        add(u << 1 | 1, t[u].l, t[u].add);
    }
    t[u].add = 0;
}

void bring_up(int u) {
    if (t[u].l == t[u].r) return;
    int l = u << 1, r = u << 1 | 1;
    push_down(l);
    push_down(r);
    t[u].s = t[l].s + t[r].s;
}

void build(int u, int l, int r) {
    t[u] = {l, r, 0, 0};
    if (l == r)
        t[u].s = a[l];
    else {
        int m = (l + r) / 2;
        build(u * 2, l, m), build(u * 2 + 1, m + 1, r);
        bring_up(u);
    }
}

void change(int u, int l, int r) {
    if (l <= t[u].l and t[u].r <= r)
        add(u, l, 1);
    else {
        push_down(u);
        int m = (t[u].l + t[u].r) / 2;
        if (m >= l) change(u * 2, l, r);
        if (m < r) change(u * 2 + 1, l, r);
        bring_up(u);
    }
}

long long query(int u, int l, int r) {
    push_down(u);
    if (l <= t[u].l and t[u].r <= r) {
        // printf("%d-%d=%lld\t", t[u].l, t[u].r, t[u].s);
        return t[u].s;
    }
    int m         = (t[u].l + t[u].r) / 2;
    long long res = 0;
    if (m >= l) res = query(u * 2, l, r);
    if (m < r) res += query(u * 2 + 1, l, r);
    return res;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    // int cnt = 0;
    while (q--) {
        scanf("%d %d %d", &b, &c, &d);
        if (b == 1) {
            change(1, c, d);
        } else {
            printf("%lld\n", query(1, c, d));
            // if (++cnt == 4) {
            // int sum = 0;
            // for (int i = 1; i <= 4 * n; i++) {
            //     if (t[i].l == t[i].r and t[i].l > 0) {
            //         printf("%d:s=%d a=%d\t", t[i].l, t[i].s, t[i].add);
            //         // if (t[i].l >= 15 and t[i].l <= 85) sum += t[i].add;
            //     }
            //     // }
            // }
            // printf("%d\n", sum);
        }
    }
}
