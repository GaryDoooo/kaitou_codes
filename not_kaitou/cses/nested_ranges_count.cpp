#include <bits/stdc++.h>
using namespace std;
struct range {
    int l, r, idx, rr;
} a[212345];
int n, l, r, ans1[212345], ans2[212345];
bool operator<(const range& a, const range& b) {
    return a.r > b.r and a.l == b.l or a.l < b.l;
}
bool cmp(const range& a, const range& b) { return a.r < b.r; }
struct tr {
    int l, r, v;
} t[212345 * 4];
void build(int u, int l, int r) {
    t[u] = {l, r, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void add(int u, int idx) {
    if (t[u].l == t[u].r) {
        t[u].v += 1;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (idx <= mid)
        add(u << 1, idx);
    else
        add(u << 1 | 1, idx);
    t[u].v++;
}
int count(int u, int l, int r) {
    if (l > r) return 0;
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1, res = 0;
    if (mid >= l) res = count(u << 1, l, r);
    if (mid < r) res += count(u << 1 | 1, l, r);
    return res;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        a[i] = {l, r, i};
    }
    sort(a, a + n, cmp);
    int k = 0;
    for (int i = 0; i < n; i++) {
        a[i].rr = ++k;
        while (a[i].r == a[i + 1].r) {
            a[++i].rr = k;
        }
    }
    // for (int i = 0; i < n; i++) cout << a[i].r << endl;
    sort(a, a + n);
    build(1, 1, k);
    // multiset<int> s;
    for (int i = 0; i < n; i++) {
        ans2[a[i].idx] = count(1, a[i].rr, k);
        add(1, a[i].rr);
        // ans2[a[i].idx] = distance(s.lower_bound(a[i].r), s.end());
        // s.insert(a[i].r);
    }
    build(1, 1, k);
    // s.clear();
    for (int i = n - 1; i >= 0; i--) {
        ans1[a[i].idx] = count(1, 1, a[i].rr);
        add(1, a[i].rr);
        // ans1[a[i].idx] = distance(s.begin(), s.upper_bound(a[i].r));
        // s.insert(a[i].r);
    }
    // sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) printf("%d ", ans1[i]);
    puts("");
    for (int i = 0; i < n; i++) printf("%d ", ans2[i]);
}
