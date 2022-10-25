#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2501;
int N, M;
vector<pair<int, int>> adj[MAXN];

bool vis[MAXN];
vector<int> toposort, cycle;
vector<long long> d(2501, -1e18);

void dfs(int v) {
    vis[v] = true;
    cout << v << endl;
    for (auto u : adj[v]) {
        if (!vis[u.first]) {
            dfs(u.first);
        }
    }
    toposort.push_back(v);
}

bool connected(int v) {
    vis[v] = true;
    if (v == N) return true;
    for (auto u : adj[v]) {
        if (!vis[u.first]) {
            if (connected(u.first)) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    dfs(1);
    if (!vis[N]) {
        cout << 0;
        return 0;
    }
    reverse(toposort.begin(), toposort.end());
    for (auto i : toposort) cout << i << " ";
    cout << endl;
    d[1] = 0;
    for (int v : toposort) {
        for (auto u : adj[v]) {
            if (d[u.first] < d[v] + u.second) {
                d[u.first] = d[v] + u.second;
            }
        }
    }
    for (auto v : toposort) {
        for (auto u : adj[v]) {
            if (d[u.first] < d[v] + u.second) {
                d[u.first] = d[v] + u.second;
                cycle.push_back(u.first);
            }
        }
    }
    cout << cycle.size() << endl;
    memset(vis, false, sizeof(vis));
    for (auto v : cycle) {
        if (!vis[v])
            if (connected(v)) {
                cout << -1;
                return 0;
            }
    }
    cout << d[N];

    return 0;
}
