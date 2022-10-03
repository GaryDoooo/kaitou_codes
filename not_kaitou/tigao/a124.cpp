#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct tree {
    int l, r;
    ll v, add;
} t[912345];
int n, f, a, b, c, k[212345];
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) {
        t[u].v = k[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    t[u].v = t[u << 1].v + t[u << 1 | 1].v;
}
void sum_up(int u) {
    t[u].v = t[u << 1].v + (t[u << 1].r - t[u << 1].l + 1) * t[u << 1].add +
             t[u << 1 | 1].v +
             (t[u << 1 | 1].r - t[u << 1 | 1].l + 1) * t[u << 1 | 1].add;
}
void pushdown_add(int u) {
    if (t[u].add > 0) {
        t[u].v += (t[u].r - t[u].l + 1) * t[u].add;
        if (t[u].l < t[u].r) {
            t[u << 1].add += t[u].add;
            t[u << 1 | 1].add += t[u].add;
            sum_up(u);  // t[u].v =
            //     t[u << 1].v + (t[u << 1].r - t[u << 1].l + 1) * t[u << 1].add
            //     + t[u << 1 | 1].v + (t[u << 1 | 1].r - t[u << 1 | 1].l + 1) *
            //     t[u << 1 | 1].add;
        }
        t[u].add = 0;
    }
}
ll get_sum(int u, int l, int r) {
    pushdown_add(u);
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1;
    ll res  = 0;
    if (mid >= l) res = get_sum(u << 1, l, r);
    if (mid < r) res += get_sum(u << 1 | 1, l, r);
    sum_up(u);  // t[u].v =
    // t[u].v = t[u << 1].v + (t[u << 1].r - t[u << 1].l + 1) * t[u << 1].add +
    //          t[u << 1 | 1].v +
    //          (t[u << 1 | 1].r - t[u << 1 | 1].l + 1) * t[u << 1 | 1].add;
    return res;
}
void add(int u, int l, int r, int a) {
    if (t[u].l >= l and t[u].r <= r) {
        t[u].add += a;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= l) add(u << 1, l, r, a);
    if (mid < r) add(u << 1 | 1, l, r, a);
    sum_up(u);  // t[u].v =
}
void sub(int u, int s) {
    t[u].v -= s;
    if (t[u].l < t[u].r) {
        sub(u << 1, s);
    }
}
int main() {
    scanf("%d%d", &n, &f);
    for (int i = 1; i <= n; i++) scanf("%d", k + i);
    build(1, 1, n);
    while (f--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d\n", &a, &b, &c);
            add(1, a, b, c);
        } else if (a == 2) {
            scanf("%d\n", &b);
            add(1, 1, 1, b);
        } else if (a == 3) {
            scanf("%d\n", &b);
            sub(1, b);
        } else if (a == 4) {
            scanf("%d%d\n", &a, &b);
            printf("%lld\n", get_sum(1, a, b));
        } else {
            printf("%lld\n", get_sum(1, 1, 1));
        }
        // for (int i = 1; i <= n * 2; i++)
        //     cout << t[i].v << "+" << t[i].add << " ";
        // cout << endl;
    }
}

