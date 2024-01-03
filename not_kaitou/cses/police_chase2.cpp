#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
    int u, v;
};
edge e[1001];
unordered_set<int> ee[501];
int vis[501], e_vis[1001], res, cur_vis_e[1001];
int distinguish_path_cnt = 0;
vector<vector<int>> paths;

int find_path(int u) {
    if (u == n) return 1;
    vis[u] = 1;
    for (int ei : ee[u]) {
        if (e_vis[ei] or cur_vis_e[ei]) continue;
        int v;
        if (u == e[ei].u)
            v = e[ei].v;
        else
            v = e[ei].u;
        if (vis[v]) continue;
        cur_vis_e[ei] = 1;
        if (find_path(v)) return 1;
        // cur_vis_e[ei] = 0;
    }
    vis[u] = 0;
    return 0;
}

int find_to_cut(int p_i) {
    for (int i : paths[p_i]) e_vis[i] = 0;
    for (int i : paths[p_i]) {
        e_vis[i] = 1;
        memset(vis, 0, sizeof(vis));
        memset(cur_vis_e, 0, sizeof(cur_vis_e));
        if (find_path(1) == 0) {
            // e_vis[i] = 0;
            return i;
        }
        e_vis[i] = 0;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[i].u = u, e[i].v = v;
        ee[u].insert(i);
        ee[v].insert(i);
    }
    do {
        memset(vis, 0, sizeof(vis));
        memset(cur_vis_e, 0, sizeof(cur_vis_e));
        res = find_path(1);
        if (res) {
            vector<int> path;
            for (int i = 1; i <= m; i++)
                if (cur_vis_e[i]) path.push_back(i), e_vis[i] = 1;
            paths.push_back(path);
            distinguish_path_cnt += res;
        }
    } while (res);
    // cout << paths.size() << endl;
    // for (auto p : paths) {
    //     for (auto e : p) cout << e << " ";
    //     cout << endl;
    // }
    cout << distinguish_path_cnt << endl;
    vector<int> edge_cut;
    while (distinguish_path_cnt--)
        edge_cut.push_back(find_to_cut(distinguish_path_cnt));
    for (int i : edge_cut) printf("%d %d\n", e[i].u, e[i].v);
}

