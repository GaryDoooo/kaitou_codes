#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
    vector<pair<int, int>> e;
    bitset<2501> fa;
    int in, vis;
} a[2501];
int n, m, u, v, w;
queue<int> q;
int vis[2501];
ll d[2501];
bitset<2501> s;
vector<int> res;
stack<int> rec;

int dfs(int u) {
    ll dis = d[u];
    rec.push(u);
    for (auto i : a[u].e) {
        int v = i.first;
        if (!s[v]) continue;
        if (vis[v]) {
            if (dis + i.second < d[v]) {
                // for (int i = 1; i <= n; i++) cout << d[i] << " ";
                // cout << endl;
                res.push_back(v);
                while (rec.size()) {
                    res.push_back(rec.top());
                    if (rec.top() == v) break;
                    rec.pop();
                }
                return 1;
            }
        } else {
            // int temp = d[v];
            d[v]   = min(d[v], dis + i.second);
            vis[v] = 1;
            if (dfs(v)) {
                // res.push_back(u);
                return 1;
            }
            vis[v] = 0;
            // d[v]   = temp;
        }
    }
    rec.pop();
    return 0;
}

int test(int start) {
    // cout << "TEST " << start << endl;
    memset(d, 1, sizeof(d));
    memset(vis, 0, sizeof(vis));
    s          = a[start].fa;
    vis[start] = 1;
    d[start]   = 0;
    if (dfs(start)) {
        puts("YES");
        for (auto it = res.rbegin(); it != res.rend(); ++it) printf("%d ", *it);
        return 1;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        a[u].e.push_back(make_pair(v, w));
        a[v].in++;
    }
    int min_in = 2501, idx;
    for (int i = 1; i <= n; i++) {
        if (!a[i].vis) q.push(i);
        while (q.size()) {
            int u = q.front();
            q.pop();
            if (a[u].vis) continue;
            a[u].vis = 1;
            for (auto i : a[u].e) {
                a[i.first].fa[u] = true;
                a[i.first].fa |= a[u].fa;
                q.push(i.first);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j = 1; j <= n; j++)
    //         if (a[i].fa[j]) cout << j << " ";
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        if (a[i].fa[i])
            if (test(i)) return 0;
    }
    cout << "NO" << endl;
}

