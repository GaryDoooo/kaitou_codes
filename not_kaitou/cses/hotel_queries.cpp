#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
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
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar(' ');
}
////////////////////////
int x[212345];
struct node {
    int l, r, v;
};
node t[812345];

void bringup(int u) { t[u].v = max(t[u << 1].v, t[u << 1 | 1].v); }

void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r)
        t[u].v = x[l];
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        bringup(u);
    }
}

int query(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1;
    int res = 0;
    if (mid < r) res = max(res, query(u << 1 | 1, l, r));
    if (mid >= l) res = max(res, query(u << 1, l, r));
    return res;
}

void change(int u, int index, int target_val) {
    if (t[u].l == t[u].r)
        t[u].v = target_val;
    else {
        int mid = t[u].l + t[u].r >> 1;
        if (index > mid)
            change(u << 1 | 1, index, target_val);
        else
            change(u << 1, index, target_val);
        bringup(u);
    }
}

int main() {
    int n = read(), q = read();
    for (int i = 1; i <= n; i++) x[i] = read();
    build(1, 1, n);
    while (q--) {
        int a = read();
        if (a > query(1, 1, n)) {
            write(0);
            continue;
        }
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            int b   = query(1, l, mid);
            if (b < a)
                l = mid + 1;
            else
                r = mid;
        }
        write(l);
        change(1, l, x[l] -= a);
    }
}
