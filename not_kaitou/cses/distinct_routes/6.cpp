#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
    int u, v;
};
edge e[1001];
unordered_set<int> ee[501];
int vis[501], e_vis[1001], cnt;

int find_path(int u) {
    if (u == n) {
        cnt++;
        return 1;
    }
    vis[u] = 1;
    for (int ei : ee[u]) {
        if (e_vis[ei] or vis[e[ei].v]) continue;
        int v;
        // if (u == e[ei].u)
        v = e[ei].v;
        // else
        //     v = e[ei].u;
        // if (vis[v]) continue;
        // cur_vis_e[ei] = 1;
        e_vis[ei] = 1;
        find_path(v);
        e_vis[ei] = 0;
    }
    vis[u] = 0;
    // cur_path.pop_back();
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[i].u = u, e[i].v = v;
        ee[u].insert(i);
    }
    find_path(1);
    cout << cnt << endl;
}
