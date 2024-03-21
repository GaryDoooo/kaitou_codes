#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, vis;
    set<int> r;  //, rbkp;
};
int n, m, max_r;
edge e[1005];
vector<int> ei[501], eo[501];
int vis[1005];
vector<vector<int>> cur_res, final_res;

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
        scanf("%d %d", &e[i].u, &e[i].v);
        eo[e[i].u].push_back(i);
        ei[e[i].v].push_back(i);
    }
    for (int i = 0; i < eo[1].size(); i++) {
        memset(vis, 0, sizeof(vis));
        dry(i, eo[1][i]);
    }
    max_r = ei[n].size();
    pick_path(0);
    cout << final_res.size() << endl;
    print_res();
}
