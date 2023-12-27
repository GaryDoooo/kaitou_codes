#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct work {
    int start, end;
    ll award;
} w[212345];
int n, a, b, c;
bool operator<(const work &a, const work &b) { return a.end < b.end; }
map<int, int> m;
set<int> s;
struct tr {
    int l, r;
    ll v;      // v is max reward end at this time point
} t[1612345];  // each work has 2 time points, so double from 4X to 8X

void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void assign(int u, int idx, ll v) {
    if (t[u].l == t[u].r) {
        t[u].v = max(v, t[u].v);
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (idx <= mid)
        assign(u << 1, idx, v);
    else
        assign(u << 1 | 1, idx, v);
    t[u].v = max(t[u << 1].v, t[u << 1 | 1].v);
}

ll get(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1;
    ll res  = 0;
    if (mid >= l) res = get(u << 1, l, r);
    if (mid < r) res = max(res, get(u << 1 | 1, l, r));
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        s.insert(a), s.insert(b);
        w[i] = {a, b, (ll)c};
    }
    sort(w, w + n);
    int idx = 0;
    for (auto i : s) m[i] = ++idx;
    // for (int i = 0; i < n; i++)
    //     cout << m[w[i].start] << " " << m[w[i].end] << " " << w[i].award
    //          << endl;
    build(1, 0, idx);
    for (int i = 0; i < n; i++)
        assign(1, m[w[i].end], get(1, 1, m[w[i].start] - 1) + w[i].award);
    cout << get(1, 1, idx);
}
