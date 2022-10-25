#include <bits/stdc++.h>
#define dis first
#define idx second
using namespace std;
using ll = long long;
int n, m, u, v, w, e_cnt, e_head[112345], k, cnt[112345];
struct edges {
    int n, v, w;
} e[212345];
priority_queue<pair<ll, int>> q;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        e[++e_cnt] = {e_head[u], v, w};
        e_head[u]  = e_cnt;
    }
    q.push({0, 1});
    while (q.size()) {
        u    = q.top().idx;
        ll d = -q.top().dis;
        q.pop();
        if (u == n) {
            printf("%lld ", d);
            if (cnt[u] >= k) return 0;
        }
        if (++cnt[u] > k) continue;
        for (int i = e_head[u]; i; i = e[i].n) {
            v = e[i].v, w = e[i].w;
            if (cnt[v] < k) q.push({-d - w, v});
        }
    }
}

