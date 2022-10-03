#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct tree {
    int l, r;
    ll v;
} t[412345];
int n, a, b, w;
char c;
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}
ll get_sum(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) return t[u].v;
    int mid = t[u].l + t[u].r >> 1;
    ll sum  = 0;
    if (mid >= l) sum = get_sum(u << 1, l, r);
    if (mid < r) sum += get_sum(u << 1 | 1, l, r);
    return sum;
}
void add(int u, int p, int v) {
    t[u].v += v;
    if (t[u].l == t[u].r) return;
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= p) add(u << 1, p, v);
    if (mid < p) add(u << 1 | 1, p, v);
}

int main() {
    scanf("%d\n%d\n", &n, &w);
    build(1, 1, n);
    while (w--) {
        scanf("%c %d %d\n", &c, &a, &b);
        if (c == 'x')
            add(1, a, b);
        else
            printf("%lld\n", get_sum(1, a, b));
    }
}
