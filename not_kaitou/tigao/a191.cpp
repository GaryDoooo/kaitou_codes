#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct cow {
    int x, v, x_order;
} c[51234];
struct tree {
    int l, r, sum, count;  //, count, add;
} t[201234];
int n;
bool cmpv(const cow& a, const cow& b) { return a.v < b.v; }
bool cmpx(const cow& a, const cow& b) { return a.x < b.x; }

void build(int u, int l, int r) {
    t[u] = {l, r, 0, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int get_sum(int u, int l, int r) {
    if (l > r) return 0;
    // pushdown(u);
    if (t[u].l >= l and t[u].r <= r) return t[u].sum;
    int res = 0, mid = t[u].l + t[u].r >> 1;
    if (l <= mid) res = get_sum(u << 1, l, r);
    if (r > mid) res += get_sum(u << 1 | 1, l, r);
    return res;
}

int get_count(int u, int l, int r) {
    if (l > r) return 0;
    // pushdown(u);
    if (t[u].l >= l and t[u].r <= r) return t[u].count;
    int res = 0, mid = t[u].l + t[u].r >> 1;
    if (l <= mid) res = get_count(u << 1, l, r);
    if (r > mid) res += get_count(u << 1 | 1, l, r);
    return res;
}

void add_cow(int u, int x_order, int x) {
    t[u].count++;
    t[u].sum += x;
    // if (t[u].l==t[u].r)
    if (t[u].r > t[u].l) {
        // t[u].add += x;
        int mid = t[u].l + t[u].r >> 1;
        if (mid >= x_order)
            add_cow(u << 1, x_order, x);
        else
            add_cow(u << 1 | 1, x_order, x);
    }
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) scanf("%d%d\n", &c[i].v, &c[i].x);
    sort(c, c + n, cmpx);
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++) c[i].x_order = i;
    sort(c, c + n, cmpv);
    add_cow(1, c[0].x_order, c[0].x);
    ll res = 0;
    for (int i = 1; i < n; i++) {
        ll left_cow_x_sum  = get_sum(1, 0, c[i].x_order - 1);
        ll right_cow_x_sum = get_sum(1, c[i].x_order + 1, n - 1);
        ll left_cow_cnt    = get_count(1, 0, c[i].x_order - 1);
        ll right_cow_cnt   = get_count(1, c[i].x_order + 1, n - 1);
        res += c[i].v * (c[i].x * left_cow_cnt - left_cow_x_sum +
                         right_cow_x_sum - right_cow_cnt * c[i].x);
        add_cow(1, c[i].x_order, c[i].x);
    }
    cout << res << endl;
}
