#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, q, m, u, v, w, vis[2501];
ll d[501][501];
vector<int> adj[501], toposort;

void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v])
        if (!vis[u]) dfs(u);
    toposort.push_back(v);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    memset(d, 127, sizeof(d));
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        if (d[u][v] > 1e10) adj[u].push_back(v), adj[v].push_back(u);
        d[u][v] = d[v][u] = min((ll)w, d[v][u]);
    }
    for (int i = 1; i <= n; i++) {
        toposort.clear();
        memset(vis, 0, sizeof(vis));
        dfs(i);
        for (auto it = toposort.rbegin(); it != toposort.rend(); it++) {
            v = *it;
            for (auto u : adj[v])
                if (d[i][u] > d[i][v] + d[v][u])
                    d[i][u] = d[u][i] = d[i][v] + d[v][u];
        }
    }
    while (q--) {
        scanf("%d%d", &u, &v);
        if (d[u][v] > 1e14)
            puts("-1");
        else
            printf("%lld\n", d[u][v]);
    }
}

