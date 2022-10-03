#include <bits/stdc++.h>
using namespace std;
pair<int, int> inp[212345];
int n, a[212345];
struct tr {
    int l, r, v;
} t[812345];
bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first or a.first == b.first and a.second > b.second;
}
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void assign(int u, int idx, int v) {
    if (t[u].l == t[u].r) {
        t[u].v = v;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (idx <= mid)
        assign(u << 1, idx, v);
    else
        assign(u << 1 | 1, idx, v);
    t[u].v = max(t[u << 1].v, t[u << 1 | 1].v);
}
int get(int u, int l, int r) {
    if (t[u].l >= l and r >= t[u].r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1;
    int res = 0;
    if (l <= mid) res = get(u << 1, l, r);
    if (r > mid) res = max(res, get(u << 1 | 1, l, r));
    return res;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i].first);
        inp[i].second = i;
    }
    sort(inp, inp + n, cmp);
    for (int i = 0; i < n; i++) a[inp[i].second] = i;
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        int f = get(1, 0, a[i]);
        assign(1, a[i], f + 1);
    }
    cout << get(1, 0, n - 1) << endl;
}
