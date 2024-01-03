#include <bits/stdc++.h>
using namespace std;
int n, m, e[4123], h[505], vis[505], edge_vis[1005];
struct state {
    char edge[1001];  // first bit unavailable, 2nd bit on previous path
};
state now, init;
queue<state> q;
vector<int> path;

int find_path(int u) {
    if (u == n) return 1;
    vis[u] = 1;
    for (int i = h[u]; i; i = e[i]) {
        int v = e[i--], idx = i >> 2;
        if (vis[v]) continue;
        if (now.edge[idx] & 1)  // if not available
            continue;
        if (edge_vis[idx]) continue;
        edge_vis[idx] = 1;
        path.push_back(idx);
        if (find_path(v)) return 1;
        path.pop_back();
        // vis_edge[idx] = 0;
    }
    vis[u] = 0;
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m * 4;) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[i++] = h[u];
        e[i]   = v;
        h[u]   = i++;
        e[i++] = h[v];
        e[i]   = u;
        h[v]   = i++;
    }
    q.push(init);
    while (!q.empty()) {
        // cout << q.size() << endl;
        now = q.front();
        q.pop();
        path.clear();
        memset(vis, 0, sizeof(vis)), vis[1] = 1;
        memset(edge_vis, 0, sizeof(edge_vis));
        if (find_path(1)) {
            // pick edge to break
            for (int i = 0; i < path.size(); i++) {
                int edge_cut = path[i];
                // int edge_cut = path.top();
                // path.pop();
                if (now.edge[edge_cut] &
                    2)  // if the edge to cut is on prev path
                    continue;
                state new_state;
                memcpy(new_state.edge, now.edge, sizeof(new_state.edge));
                new_state.edge[edge_cut] |= 1;
                for (int j = i + 1; j < path.size(); j++)
                    new_state.edge[path[j]] |= 2;
                q.push(new_state);
            }
        } else {
            // print and return
            int res = 0;
            for (int i = 1; i <= m; i++)
                if (now.edge[i] & 1) res++;
            cout << res << endl;
            return 0;
        }
    }
}
