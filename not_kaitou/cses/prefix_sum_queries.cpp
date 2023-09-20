#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MIN_LL -2223372036854775808
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
////////////////////////
int n, q;
struct node {
    int l, r;
    ll s;  // sum of all the nodes on this tree, s= s_left + s_right
    ll m;  // max of prefix sum in this tree,
           // m = max (m_left , s_left + m_right)
};
struct res {
    ll s, m;
};
node t[812345];
int x[212345];

void bring_up(int u) {
    if (t[u].l < t[u].r) {
        t[u].s = t[u * 2].s + t[u * 2 + 1].s;
        t[u].m = max(t[u * 2].m, t[u * 2 + 1].m + t[u * 2].s);
    }
}

void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r)
        t[u].s = t[u].m = x[l];
    else {
        int mid = (l + r) / 2;
        build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
        bring_up(u);
    }
}

void change(int u, int k, int val) {
    if (t[u].l == t[u].r)
        t[u].s = t[u].m = (ll)val;
    else {
        int mid = (t[u].l + t[u].r) / 2;
        if (k <= mid)
            change(u * 2, k, val);
        else
            change(u * 2 + 1, k, val);
        bring_up(u);
    }
}

res query(int u, int l, int r) {
    res result;
    if (t[u].l >= l and t[u].r <= r) {
        result = {t[u].s, t[u].m};
        return result;
    } else {
        res rl = {0, MIN_LL}, rr = {0, MIN_LL};
        int mid = (t[u].l + t[u].r) / 2;
        if (l <= mid) rl = query(u * 2, l, r);
        if (r > mid) rr = query(u * 2 + 1, l, r);
        result.s = rl.s + rr.s;
        result.m = max(rl.m, rl.s + rr.m);
    }
    // cout << "l=" << t[u].l << " r=" << t[u].r << " s=" << result.s
    //      << " m=" << result.m << endl;
    return result;
}

int main() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) x[i] = read();
    build(1, 1, n);
    while (q--) {
        int a = read(), b = read(), c = read();
        if (a == 1)
            change(1, b, c);
        else
            printf("%lld ", max((ll)0, (query(1, b, c).m)));
    }
}

