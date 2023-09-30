#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r;
    long long sum;
    long long chg_to, add_by;
};
int n, q, b, a[212345];
node t[812345];

void push_down(int u) {
    if (t[u].chg_to) t[u].sum = t[u].chg_to * (t[u].r - t[u].l + 1);
    // else
    t[u].sum += t[u].add_by * (t[u].r - t[u].l + 1);
    if (t[u].l < t[u].r) {
        int l = u << 1, r = u << 1 | 1;
        if (t[u].chg_to) {
            t[l].chg_to = t[r].chg_to = t[u].chg_to;
            t[r].add_by = t[l].add_by = 0;
        }
        t[l].add_by += t[u].add_by;
        t[r].add_by += t[u].add_by;
        // t[l].chg_to = t[r].chg_to = 0;
    }
    t[u].chg_to = t[u].add_by = 0;
}

void bringup(int u) {
    int l = u << 1, r = u << 1 | 1;
    push_down(l), push_down(r);
    t[u].sum = t[l].sum + t[r].sum;
}

void build(int u, int l, int r) {
    t[u] = {l, r, 0, 0, 0};
    if (l == r) {
        t[u].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    bringup(u);
}

void add_x(int u, int l, int r, int x) {
    push_down(u);
    if (t[u].l >= l and t[u].r <= r) {
        // t[u].sum += x * (t[u].r - t[u].l + 1);
        t[u].add_by = x;
        // push_down(u);
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= l) add_x(u << 1, l, r, x);
    if (mid < r) add_x(u << 1 | 1, l, r, x);
    bringup(u);
}

void set_x(int u, int l, int r, int x) {
    push_down(u);
    if (t[u].l >= l and t[u].r <= r) {
        // t[u].sum    = x * (t[u].r - t[u].l + 1);
        t[u].chg_to = x;
        // t[u].add_by = 0;
        // push_down(u);
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= l) set_x(u << 1, l, r, x);
    if (mid < r) set_x(u << 1 | 1, l, r, x);
    bringup(u);
}

long long query(int u, int l, int r) {
    push_down(u);
    if (t[u].l >= l and t[u].r <= r) return t[u].sum;
    int mid       = t[u].l + t[u].r >> 1;
    long long res = 0;
    if (mid >= l) res = query(u << 1, l, r);
    if (mid < r) res += query(u << 1 | 1, l, r);
    return res;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    while (q--) {
        scanf("%d", &b);
        if (b == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            add_x(1, l, r, x);
        } else if (b == 2) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            set_x(1, l, r, x);
        } else if (b == 3) {
            int l, r;
            scanf("%d %d", &l, &r);
            // for (int i = 1; i < 24; i++)
            //     printf("%d:l=%d r=%d s=%lld add=%d ch=%d\n", i, t[i].l,
            //     t[i].r,
            //            t[i].sum, t[i].add_by, t[i].chg_to);
            printf("%lld\n", query(1, l, r));
            // for (int i = 1; i < 24; i++)
            //     printf("%d:l=%d r=%d s=%lld add=%d ch=%d\n", i, t[i].l,
            //     t[i].r,
            //            t[i].sum, t[i].add_by, t[i].chg_to);
        }
    }
}

