#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct tr {
    int l, r, start, end, cnt;
    ll cost, sum;
} t[812345];
int s[212345];
int n, q, a, b, x[212345], s_cnt;
// bool operator<(const tr &a, const tr &b) { return a.l < b.l; }
// void bring_up(tr &to, tr &a1, tr &a2) {
// int gap=max(0,a1.end-a2.start);
// ll cost_to_lift=(ll)a2.cnt * (ll)gap;
ll count(int min_x, int u) {
    // cout << " count ";
    // cout << "l" << t[u].l << "r" << t[u].r << " ";
    // cout << t[u].cost << " " << t[u].cnt << " " << t[u].sum << " " <<
    // t[u].start
    //      << " " << t[u].end << endl;
    if (t[u].start >= min_x) return t[u].cost;
    if (t[u].end <= min_x) return (ll)min_x * (ll)t[u].cnt - t[u].sum;
    // if (t[u].l == t[u].r) return (ll)(min_x - t[u].start);
    return count(min_x, u << 1) + count(max(min_x, t[u << 1].end), u << 1 | 1);
}
void bring_up(int u) {
    int left   = u << 1;
    int right  = left | 1;
    t[u].start = t[left].start;
    t[u].end   = max(t[left].end, t[right].end);
    t[u].cnt   = t[left].cnt + t[right].cnt;
    t[u].sum   = t[left].sum + t[right].sum;
    t[u].cost  = t[left].cost + count(t[left].end, right);
}
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) {
        t[u].sum = t[u].start = t[u].end = x[l];
        t[u].cnt                         = 1;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    bring_up(u);  //, t[u << 1], u << 1 | 1i);
}
void build_subarray(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) {
        s[s_cnt++] = u;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (l <= mid) build_subarray(u << 1, l, r);
    if (r > mid) build_subarray(u << 1 | 1, l, r);
}
bool cmp(int u, int v) { return t[u].l < t[v].l; }
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    build(1, 1, n);
    while (q--) {
        scanf("%d%d", &a, &b);
        // for (int i = a; i <= b; i++) cout << x[i] << " ";
        // cout << endl;
        s_cnt = 0;
        build_subarray(1, a, b);
        sort(s, s + s_cnt, cmp);
        ll res        = 0;
        int current_x = 0;
        for (int i = 0; i < s_cnt; i++) {
            // cout << "l" << t[s[i]].l << "r" << t[s[i]].r << " ";
            res += count(current_x, s[i]);
            // cout << current_x << " " << res << endl;
            current_x = max(current_x, t[s[i]].end);
        }
        printf("%lld\n", res);
    }
}

