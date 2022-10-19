#include <bits/stdc++.h>
using namespace std;
int n, m, in[112345], out[112345], eh[112345], e_cnt, r[112345], u, v;
struct edge {
    int nxt, v, done, u;
} e[212345];
vector<pair<int, int>> e_in[112345];
queue<int> q;
stack<int> path;
int the_root, the_c[112345], vis[112345], on_cycle[112345];

int get_root(int x) {
    int t = x;
    while (r[x]) x = r[x];
    if (t != x) r[t] = x;
    return x;
}
void combine(int x, int y) {
    int xr = get_root(x), yr = get_root(y);
    if (xr != yr) r[yr] = xr;
}

void print(int u) {
    vector<int> res;
    res.push_back(u);
    while (path.size()) {
        res.push_back(path.top());
        if (path.top() == u) break;
        path.pop();
    }
    printf("%ld\n", res.size());
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        printf("%d ", *it);
    }
}

void dfs(int u) {
    path.push(u);
    for (int i = eh[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (the_c[v]) {
            if (vis[v]) {
                print(v);
                exit(0);
            } else {
                vis[v] = 1;
                dfs(v);
                vis[v] = 0;
            }
        }
    }
    path.pop();
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        e[++e_cnt] = {eh[u], v, 0, u};
        eh[u]      = e_cnt;
        in[v]++, out[u]++;
        e_in[v].push_back({u, e_cnt});
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i);
    while (q.size()) {
        u = q.front(), q.pop();
        for (int i = eh[u]; i; i = e[i].nxt) {
            v         = e[i].v;
            e[i].done = 1;
            if (--in[v] == 0) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (out[i] == 0) q.push(i);
    while (q.size()) {
        u = q.front(), q.pop();
        for (auto i : e_in[u]) {
            e[i.second].done = 1;
            if (--out[i.first] == 0) q.push(i.first);
        }
    }
    for (int i = 1; i <= e_cnt; i++)
        if (!e[i].done) {
            on_cycle[e[i].u] = on_cycle[e[i].v] = 1;
            combine(e[i].u, e[i].v);
        }
    for (int i = 1; i <= n; i++)
        if (on_cycle[i]) {
            int ri = get_root(i);
            if (the_root == 0) the_root = ri;
            the_c[i] = (ri == the_root);
        }
    vis[the_root] = 1;
    dfs(the_root);
    cout << "IMPOSSIBLE" << endl;
}

