//
// This is to print a sub graph that related to paths from point A to B
// The program will read u v w, and print them
// input n nodes, and m edges
//
#include <bits/stdc++.h>
#define START 71
#define GOAL 495
using namespace std;
int n, m, u, v, w, d[11234][11234], vis[11234], on_path[11234];
stack<int> path;
vector<int> adj[11234];
set<pair<int, int>> res;

void add_pair(int x, int y) {
    if (x > y) swap(x, y);
    if (x != y) res.insert(make_pair(x, y));
}

void add_path() {
    // int last = GOAL;
    stack<int> temp;
    temp = path;
    // bool have1 = false;
    while (temp.size()) {
        // add_pair(temp.top(), last);
        // last =
        // if (temp.top() == 1) have1 = true;
        on_path[temp.top()] = 1;
        temp.pop();
    }
    // if (have1) {
    //     temp = path;
    //     while (temp.size()) cout << temp.top() << " ", temp.pop();
    //     cout << endl;
    // }
    // cout << temp.size() << " " << path.size() << endl;
}

void dfs(int v, int fa) {
    if (on_path[v]) {
        add_path();
        return;
    }
    vis[v] = 1;
    path.push(v);
    for (auto u : adj[v]) {
        if (u == fa) continue;
        if (!vis[u])
            dfs(u, v);
        else if (on_path[u] and u != START) {
            // if (v == 1) cout << u << endl;
            add_path();
        }
    }
    path.pop();
    // vis[v] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(d, 127, sizeof(d));
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        if (d[u][v] > 1e9) adj[u].push_back(v), adj[v].push_back(u);
        d[u][v] = d[v][u] = min(d[u][v], w);
    }
    // cout << d[1][123] << endl;
    // for (auto i : adj[1]) cout << i << " ";
    // cout << endl;
    on_path[GOAL] = 1;
    dfs(START, 0);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (d[i][j] <= 1e9 and on_path[i] and on_path[j]) add_pair(i, j);
    cout << res.size() << endl;
    for (auto i : res)
        cout << i.first << " " << i.second << " " << d[i.first][i.second]
             << endl;
}

