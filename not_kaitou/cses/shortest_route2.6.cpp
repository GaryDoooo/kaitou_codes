#include <bits/stdc++.h>
#define idx second
using namespace std;
using ll = long long;
int n, m, t, u, v, w, done[505];
ll d[505][505];
vector<int> e[505];
priority_queue<pair<ll, int>> q;
int main() {
    scanf("%d%d%d", &n, &m, &t);
    memset(d, 1, sizeof(d));
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        if (d[u][v] > 1e10) e[u].push_back(v), e[v].push_back(u);
        d[u][v] = d[v][u] = min(d[u][v], (ll)w);
    }
    for (int i = 1; i <= n; i++) sort(e[i].rbegin(), e[i].rend());
    for (int s = 1; s < n; s++) {
        memset(done, 0, sizeof(done));
        done[s] = 1;
        for (int i = 1; i <= n; i++)
            if (i != s and d[s][i] < 1e13) q.push({-d[s][i], i});
        while (q.size()) {
            u = q.top().idx, q.pop();
            if (done[u]) continue;
            done[u] = 1;
            for (auto v : e[u]) {
                if (v < s) break;
                if (!done[v]) {
                    ll dis = d[u][v] + d[s][u];
                    if (d[s][v] > dis) {
                        d[s][v] = d[v][s] = dis;
                        q.push({-d[s][v], v});
                    }
                }
            }
        }
    }
    while (t--) {
        scanf("%d%d", &u, &v);
        if (d[u][v] > 1e13)
            puts("-1");
        else
            printf("%lld\n", d[u][v]);
    }
}
