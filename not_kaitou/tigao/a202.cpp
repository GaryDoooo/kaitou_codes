#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
vector<int> p[112345];
struct tree {
    int l, r, v;
} t[412345];
int n, a;
ll res;
void build(int u, int l, int r) {
    t[u] = {l, r, 1};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    t[u].v = t[u << 1].v + t[u << 1 | 1].v;
}
int count(int u, int l, int r) {
    if (l > r) return 0;
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1, res = 0;
    if (mid >= l) res = count(u << 1, l, r);
    if (mid < r) res += count(u << 1 | 1, l, r);
    return res;
}
void del(int u, int x) {
    t[u].v--;
    if (t[u].l == t[u].r) return;
    int mid = t[u].l + t[u].r >> 1;
    if (x <= mid) del(u << 1, x);
    if (x > mid) del(u << 1 | 1, x);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        p[a].push_back(i);
    }
    build(1, 0, n - 1);
    puts("0");
    for (int i = 1; i < n; i++) {
        for (int j : p[i - 1]) {
            res += count(1, 0, j - 1);
            del(1, j);
        }
        printf("%lld\n", res);
    }
}
