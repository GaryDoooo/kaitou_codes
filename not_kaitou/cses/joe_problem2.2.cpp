#include <bits/stdc++.h>
using namespace std;
struct tr {
    int l, r, v;
} t[212345 * 4];
int n, k;
void bring_up(int u) { t[u].v = t[u << 1].v + t[u << 1 | 1].v; }
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) {
        t[u].v = 1;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    bring_up(u);
}
void cut(int u, int cnt) {
    if (t[u].l == t[u].r) {
        cout << t[u].l << " ";
        t[u].v = 0;
        return;
    }
    if (t[u << 1].v >= cnt)
        cut(u << 1, cnt);
    else
        cut(u << 1 | 1, cnt - t[u << 1].v);
    bring_up(u);
}

int main() {
    cin >> n >> k;
    build(1, 1, n);
    // for (int i = 1; i <= n; i++) s.insert(i);
    int p = n - 1;
    for (int i = 0; i < n; i++) {
        p = (p + k + 1) % (n - i);
        // auto it = s.begin();
        // it      = it + p;
        // cout << "cut " << p << endl;
        cut(1, 1 + p--);
        // cout << *it << " ";
        // s.erase(it);
    }
}

