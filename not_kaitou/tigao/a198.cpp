#include <bits/stdc++.h>
using namespace std;
struct tr {
    int l, r, on, add;
} t[412345];
int n, m, a, b, c;
void build(int u, int l, int r) {
    t[u] = {l, r};
    // cout << "build " << u << endl;
    if (l < r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}
int calc(int u) {
    if (t[u].add & 1)
        return t[u].r - t[u].l + 1 - t[u].on;
    else
        return t[u].on;
}
void pushdown(int u) {
    if (t[u].l == t[u].r) {
        t[u].on = calc(u);
    } else {
        int l = u << 1;
        int r = l | 1;
        t[l].add += t[u].add;
        t[r].add += t[u].add;
        t[u].on = calc(r) + calc(l);
    }
    t[u].add = 0;
}
void toggle(int u, int l, int r) {
    // cout << "toggle " << u << " " << l << " " << r << endl;
    if (t[u].l >= l and t[u].r <= r)
        t[u].add++;
    else {
        pushdown(u);
        int mid = t[u].l + t[u].r >> 1;
        if (mid >= l) toggle(u << 1, l, r);
        if (mid < r) toggle(u << 1 | 1, l, r);
        t[u].on = calc(u << 1 | 1) + calc(u << 1);
    }
}
int count(int u, int l, int r) {
    pushdown(u);
    if (t[u].l >= l and t[u].r <= r) return t[u].on;
    int mid = t[u].l + t[u].r >> 1, res = 0;
    if (mid >= l) res = count(u << 1, l, r);
    if (mid < r) res += count(u << 1 | 1, l, r);
    t[u].on = calc(u << 1 | 1) + calc(u << 1);
    return res;
}

int main() {
    scanf("%d%d\n", &n, &m);
    build(1, 1, n);
    while (m--) {
        scanf("%d%d%d\n", &a, &b, &c);
        if (a)
            printf("%d\n", count(1, b, c));
        else
            toggle(1, b, c);
        // for (int i = 1; i < 20; i++) cout << t[i].on << "+" << t[i].add << "
        // "; cout << endl;
    }
}
