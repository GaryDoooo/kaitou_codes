#include <bits/stdc++.h>
using namespace std;
struct tr {
    int l, r, left, right, mid, start, change;
} t[201234];
int n, m, a, b, c;
void build(int u, int l, int r) {
    int len = r - l + 1;
    t[u]    = {l, r, len, len, len, l};
    if (l < r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}
tr calc(int u) {
    tr res;
    if (t[u].change == 1) {  // check out
        int len = t[u].r - t[u].l + 1;
        res     = {t[u].l, t[u].r, len, len, len, t[u].l, 0};
        return res;
    } else if (t[u].change == 2) {  // check in
        res = {t[u].l, t[u].r, 0, 0, 0, 0, 0};
        return res;
    } else
        return t[u];
}
void bringup(int u) {
    if (t[u].l == t[u].r) return;
    tr l = calc(u << 1), r = calc(u << 1 | 1);
    if (l.left < l.r - l.l + 1)
        t[u].left = l.left;
    else
        t[u].left = l.r - l.l + 1 + r.left;
    if (r.right < r.r - r.l + 1)
        t[u].right = r.right;
    else
        t[u].right = r.r - r.l + 1 + l.right;
    int m = t[u].mid = max(max(max(l.mid, r.mid), l.right + r.left),
                           max(t[u].left, t[u].right));
    if (m == t[u].left)
        t[u].start = l.l;
    else if (m == l.mid)
        t[u].start = l.start;
    else if (m == l.right + r.left or m == l.right + r.r - r.l + 1)
        t[u].start = l.r - l.right + 1;
    else if (m == r.mid)
        t[u].start = r.start;
    else
        t[u].start = r.r - r.right + 1;
}
void pushdown(int u) {
    if (t[u].change == 0) return;
    if (t[u].l == t[u].r) {
        t[u] = calc(u);
        return;
    }
    t[u << 1].change     = t[u].change;
    t[u << 1 | 1].change = t[u].change;
    bringup(u);
    t[u].change = 0;
}
int find_room(int u, int x) {
    pushdown(u);
    if (t[u].mid < x) return 1e9;
    int res = t[u].start;
    if (t[u].left >= x) return t[u].l;
    if (t[u].l == t[u].r) return t[u].l;
    int mid = t[u].l + t[u].r >> 1;
    res     = min(res, find_room(u << 1, x));
    if (res > mid) res = min(res, find_room(u << 1 | 1, x));
    bringup(u);
    if (t[u << 1].right + t[u << 1 | 1].left >= x)
        res = min(res, t[u << 1].r - t[u << 1].right + 1);
    return res;
}

// void pushdown_all(int u) {
//     pushdown(u);
//     if (t[u].l == t[u].r) return;
//     pushdown_all(u << 1), pushdown_all(u << 1 | 1);
//     bringup(u);
// }
//
// int finding(int u, int l, int r) {
//     if (t[u].l == t[u].r)
//         if (t[u].l >= l and t[u].l <= r)
//             return t[u].mid;
//         else
//             return 0;
//     int mid = t[u].l + t[u].r >> 1, res = 0;
//     if (mid >= l) res = finding(u << 1, l, r);
//     if (mid < r) res += finding(u << 1 | 1, l, r);
//     return res;
// }
// int find_room(int u, int x) {
//     pushdown_all(1);
//     for (int i = 1; i + x - 1 <= n; i++) {
//         if (finding(1, i, i + x - 1) == x) return i;
//     }
//     return 1e9;
// }

void check(int u, int l, int r, int change) {
    if (t[u].l >= l and t[u].r <= r) {
        t[u].change = change;
        // t[u]=calc(u);
        return;
    }
    pushdown(u);
    int mid = t[u].l + t[u].r >> 1;
    if (mid < r) check(u << 1 | 1, l, r, change);
    if (mid >= l) check(u << 1, l, r, change);
    bringup(u);
}
int main() {
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while (m--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            c = find_room(1, b);
            if (c > 1e8)
                puts("0");
            else {
                printf("%d\n", c);
                check(1, c, c + b - 1, 2);
            }
        } else {
            scanf("%d%d", &b, &c);
            check(1, b, b + c - 1, 1);
        }
        // for (int i = 1; i < 20; i++)
        //     cout << "l" << t[i].l << "r" << t[i].r << ":" << t[i].left << "-"
        //          << t[i].right << "-" << t[i].mid << "-" << t[i].start << "-"
        //          << t[i].change << " ";
        // cout << endl;
    }
}
