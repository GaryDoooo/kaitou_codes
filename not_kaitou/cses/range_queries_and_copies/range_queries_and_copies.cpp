#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct tr {
    int l, r;
    vector<ll> s;
    queue<int> cp_todo;
} t[812345];
int n, x[212345], a, b, q, c, cnt = 1;
void s_bring_up(int u, int k) {
    t[u].s[k] = t[u << 1].s[k] + t[u << 1 | 1].s[k];
}
void cp_push_down(int u) {
    while (!t[u].cp_todo.empty()) {
        int to_cp_k_idx = t[u].cp_todo.front();
        t[u].s.push_back(t[u].s[to_cp_k_idx]);
        if (t[u].l < t[u].r) {
            t[u << 1].cp_todo.push(to_cp_k_idx);
            t[u << 1 | 1].cp_todo.push(to_cp_k_idx);
        }
        t[u].cp_todo.pop();
    }
}
void build(int u, int l, int r) {
    t[u] = {l, r};
    t[u].s.push_back(0);
    if (l == r) {
        t[u].s[0] = x[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    s_bring_up(u, 0);
}
void cp(int k) { t[1].cp_todo.push(k); }
int diff;
void set_(int u, int k, int idx, int x) {
    cp_push_down(u);
    if (t[u].l == t[u].r) {
        diff      = x - t[u].s[k];
        t[u].s[k] = x;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= idx)
        set_(u << 1, k, idx, x);
    else
        set_(u << 1 | 1, k, idx, x);
    t[u].s[k] += diff;
    // s_bring_up(u, k);
}
ll get(int u, int k, int l, int r) {
    cp_push_down(u);
    if (t[u].l >= l and t[u].r <= r) return t[u].s[k];
    int mid = t[u].l + t[u].r >> 1;
    ll res  = 0;
    if (mid >= l) res = get(u << 1, k, l, r);
    if (mid < r) res += get(u << 1 | 1, k, l, r);
    return res;
}
void print() {
    for (int u = 1; u <= 10; u++) {
        cout << "u=" << u << " l=" << t[u].l << " r=" << t[u].r << " ";
        cout << "s(";
        for (int i : t[u].s) cout << i << ",";
        // cout << ") cp(";
        // for (int i : t[u].cp_todo) cout << i << ",";
        cout << ")" << endl;
    }
    cout << endl;
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    build(1, 1, n);
    // 8 print();
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &a, &b, &c);
            set_(1, a - 1, b, c);
            // print();
        } else if (a == 2) {
            scanf("%d%d%d", &a, &b, &c);
            printf("%lld\n", get(1, a - 1, b, c));
            // print();
        } else {
            scanf("%d", &a);
            cp(a - 1);
            // print();
            // cnt++;
        }
    }
}
