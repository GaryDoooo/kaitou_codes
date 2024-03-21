#include <bits/stdc++.h>
using namespace std;

unordered_set<int> ee[501];
int vis[1001], e_vis[1001], res, cur_vis_e[1001];
int distinguish_path_cnt = 0;
vector<vector<int>> paths;
vector<int> cur_path;
struct edge {
    int u, v, vis;
    set<int> r;  //, rbkp;
};
int n, m, max_r;
edge e[1005];
vector<int> ei[501], eo[501];
vector<vector<int>> cur_res, final_res;

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

void dry(int code, int edge_idx) {
    e[edge_idx].r.insert(code);
    // e[edge_idx].rbkp.insert(code);
    vis[edge_idx] = 1;
    if (e[edge_idx].v == n) return;
    for (int i : eo[e[edge_idx].v]) {
        if (vis[i]) continue;
        dry(code, i);
    }
}

void record_res(vector<int> &input) {
    vector<int> t(input.begin(), input.end());
    cur_res.push_back(t);
}

void pop_res() { cur_res.pop_back(); }

void copy_res() {
    final_res.clear();
    for (auto i : cur_res) {
        vector<int> t(i.begin(), i.end());
        final_res.push_back(t);
    }
}

void print_res() {
    for (auto i : final_res) {
        printf("%ld\n1 ", i.size() + 1);
        for (int j = i.size() - 1; j >= 0; j--) printf("%d ", e[i[j]].v);
        puts("");
    }
}

int pick_path(int cnt) {
    if (cnt >= max_r) {
        copy_res();
        return 1;
    }
    vector<int> candidates;
    for (int i : ei[n])
        if (e[i].r.size() > 0 and e[i].vis == 0) candidates.push_back(i);
    if (candidates.size() == 0) {
        if (cur_res.size() > final_res.size()) copy_res();
        return 0;
    }
    int pick = candidates[0];
    for (int i : candidates)
        if (e[i].r.size() < e[pick].r.size()) pick = i;
    // cout << pick << endl;
    // bool no_path= true;
    for (int code : e[pick].r) {
        // cout << cnt << ".>" << code << endl;
        vector<int> path, has_code;
        path.push_back(pick);
        e[pick].vis     = 1;
        int now         = e[pick].u;
        bool found_path = true;
        while (now > 1) {
            int min_len = 2000, min_pick = 0;
            for (int i : ei[now])
                if (e[i].r.size() < min_len and
                    e[i].r.find(code) != e[i].r.end() and e[i].vis == 0) {
                    min_len  = e[i].r.size();
                    min_pick = i;
                }
            if (min_len == 2000) {
                found_path = false;
                break;
            }
            path.push_back(min_pick);
            e[min_pick].vis = 1;
            now             = e[min_pick].u;
        }
        for (int i = 1; i <= m; i++)
            if (e[i].r.find(code) != e[i].r.end()) {
                has_code.push_back(i);
                e[i].r.erase(code);
            }
        if (found_path) record_res(path);
        // cout << "here " << cnt << " " << code << endl;
        if (pick_path(cnt + 1)) return 1;
        for (int i : has_code) e[i].r.insert(code);
        if (found_path) pop_res();
        for (int i : path) e[i].vis = 0;
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
        // ee[v].insert(i);
        eo[e[i].u].push_back(i);
        ei[e[i].v].push_back(i);
    }
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
    for (int i = 0; i < eo[1].size(); i++) {
        memset(vis, 0, sizeof(vis));
        dry(i, eo[1][i]);
    }
    memset(vis, 0, sizeof(vis));
    max_r = ei[n].size();
    pick_path(0);
    if (final_res.size() > distinguish_path_cnt) {
        cout << final_res.size() << endl;
        print_res();
    } else {
        cout << distinguish_path_cnt << endl;
        for (auto path : paths) {
            printf("%ld\n", path.size());
            for (int i : path) printf("%d ", i);
            printf("\n");
        }
    }
}

