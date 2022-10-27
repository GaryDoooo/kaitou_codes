#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n, m, u, v, c, cnt, r[N];
struct edges {
    int u, v, c;
    friend bool operator<(const edges& a, const edges& b) { return a.c > b.c; }
};
priority_queue<edges> q;
long long res;

int get_root(int u) {
    int t = u;
    while (r[u]) u = r[u];
    if (t != u) r[t] = u;
    return u;
}

void combine(int u, int v) {
    // int ru = get_root(u), rv = get_root(v);
    if (u != v) r[v] = u;
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        q.push(edges{u, v, c});
    }
    while (q.size()) {
        auto e = q.top();
        q.pop();
        int ru = get_root(e.u), rv = get_root(e.v);
        if (ru == rv) continue;
        cnt++;
        res += e.c;
        combine(ru, rv);
    }
    if (cnt < n - 1)
        puts("IMPOSSIBLE");
    else
        printf("%lld", res);
}
