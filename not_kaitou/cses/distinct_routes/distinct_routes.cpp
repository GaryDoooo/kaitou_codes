#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
    int u, v;
};
edge e[1001];
unordered_set<int> ee[501];
// vector<int> ee[501];
int vis[501], e_vis[1001], res, cur_vis_e[1001];
int distinguish_path_cnt = 0;
vector<vector<int>> paths;
vector<int> cur_path;

int find_path(int u) {
    cur_path.push_back(u);
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
        cout << "path " << e[ei].u << " -> " << e[ei].v << endl;
        if (find_path(v)) return 1;
        // cur_vis_e[ei] = 0;
    }
    vis[u] = 0;
    cur_path.pop_back();
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
        // ee[u].push_back(i);
        ee[u].insert(i);
        // ee[v].insert(i);
    }
    for (int i : ee[2]) cout << e[i].u << "->" << e[i].v << endl;
    do {
        memset(vis, 0, sizeof(vis));
        memset(cur_vis_e, 0, sizeof(cur_vis_e));
        cur_path.clear();
        res = find_path(1);
        if (res) {
            paths.push_back(cur_path);
            vector<int> path;
            for (int i = 1; i <= m; i++)
                if (cur_vis_e[i]) path.push_back(i), e_vis[i] = 1;
            // paths.push_back(path);
            distinguish_path_cnt += res;
        }
    } while (res);
    cout << distinguish_path_cnt << endl;
    for (auto path : paths) {
        printf("%ld\n", path.size());
        for (int i : path) printf("%d ", i);
        printf("\n");
    }
}
