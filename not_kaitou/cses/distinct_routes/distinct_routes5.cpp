#include <bits/stdc++.h>
using namespace std;
class edge {
public:
    int u, v, vis, cnt = 0;
    void add_r(int r);
    void rm_r(int r);
    int has_r(int r);
    vector<int> list_r();

private:
    int r_tag[505];
    unordered_set<int> rset;
};

int n, m, max_r;
edge e[1005];
vector<int> ei[501], eo[501];
int vis[1005];
vector<vector<int>> cur_res, final_res;
vector<int> clr2ei[1005];

void edge::add_r(int r) {
    this->cnt++;
    this->r_tag[r] = 1;
    this->rset.insert(r);
}

int edge::has_r(int r) { return this->r_tag[r]; }

void edge::rm_r(int r) {
    this->cnt--;
    this->r_tag[r] = 0;
}

vector<int> edge::list_r() {
    vector<int> res;
    for (int r : this->rset)
        if (this->has_r(r)) res.push_back(r);
    return res;
}

void dry(int code, int edge_idx) {
    e[edge_idx].add_r(code);
    clr2ei[code].push_back(edge_idx);
    vis[edge_idx] = 1;
    if (e[edge_idx].v == n or e[edge_idx].v == 1) return;
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

void rm_a_color(int r) {
    for (int i = 1; i <= m; i++)
        if (e[i].has_r(r)) e[i].rm_r(r);
}

void resort_a_color(int r) {
    for (int ei : clr2ei[r])
        if (!e[ei].has_r(r)) e[ei].add_r(r);
}

/*
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
                if (e[i].cnt < min_len and
                    e[i].has_r(code) and e[i].vis == 0) {
                    min_len  = e[i].cnt;
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
*/

int trace_back(int e_i, int code, vector<int> &path, int path_cnt,
               vector<int> &node_vis);

int pick_path(int path_cnt) {
    // Max is every of out routes from 1 gets a path
    if (path_cnt == max_r) {
        copy_res();
        return 1;  // 1 means found the best answer
    }
    // Get the in route to N that with most less route code
    // But can't include the route visited
    vector<int> candidates;
    for (int edge_idx : ei[n])
        if (e[edge_idx].cnt > 0 and e[edge_idx].vis == 0)
            candidates.push_back(edge_idx);
    // if there is no edges left in the in edges to N
    // record the res, if path # is higher
    if (candidates.empty()) {
        if (cur_res.size() > final_res.size()) copy_res();
        return 0;
    }
    // Get the edge with lowest count of route codes
    int picked_edge_i = candidates[0];
    for (int candidate : candidates)
        if (e[candidate].cnt < e[picked_edge_i].cnt) picked_edge_i = candidate;
    // now use the picked route (in route to N) to trace back to 1
    // try each route code on this edge, but if all code don't work, still need
    // try next in route,
    // cout << "start picked edge_idx " << picked_edge_i << endl;
    bool found_path   = false;
    vector<int> codes = e[picked_edge_i].list_r();
    for (int code : codes) {
        vector<int> path;
        vector<int> node_vis(503, 0);
        int res = trace_back(picked_edge_i, code, path, path_cnt, node_vis);
        if (res > 0) found_path = true;
        if (res == 1) return 1;
    }
    if (!found_path) {
        e[picked_edge_i].vis = 1;
        pick_path(path_cnt);
        e[picked_edge_i].vis = 0;
    }
    return 0;
}

int trace_back(int e_i, int code, vector<int> &path, int path_cnt,
               vector<int> &node_vis) {
    path.push_back(e_i);
    e[e_i].vis = 1;
    e[e_i].rm_r(code);
    bool found_path = false;
    if (e[e_i].u == 1)  // reach to the target
    {
        record_res(path);
        // cout << "add path len:" << path.size() << endl;
        // for (int i = 1; i <= m; i++) {
        //     cout << i << ": ";
        //     for (int j : e[i].list_r()) cout << j << " ";
        //     cout << endl;
        // }
        int res = pick_path(path_cnt + 1);
        // cout << "pick_path return " << res << endl;
        pop_res();
        if (res)
            return 1;
        else
            return 2;
    } else {
        int node_now       = e[e_i].u;
        node_vis[node_now] = 1;
        for (int nxt_e_i : ei[node_now]) {
            // if (node_now == 2)
            //     cout << "code=" << code << " node 2 to nxt ei " << nxt_e_i
            //          << " has color " << e[nxt_e_i].has_r(code) << endl;
            if (e[nxt_e_i].vis or node_vis[e[nxt_e_i].u]) continue;
            if (e[nxt_e_i].has_r(code)) {
                // cout << node_now << " E I nxt:" << nxt_e_i << endl;
                // if (node_now == 5) cout << "e i at 5 " << nxt_e_i << endl;
                // if (node_now == 2) cout << "e i at 2 " << nxt_e_i << endl;
                int res = trace_back(nxt_e_i, code, path, path_cnt, node_vis);
                if (res == 1) return 1;
                if (res > 0) found_path = true;
            }
        }
        node_vis[node_now] = 0;
    }
    path.pop_back();
    e[e_i].vis = 0;
    e[e_i].add_r(code);
    if (found_path)
        return 2;
    else
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
    // for (int i = 1; i <= m; i++) {
    //     cout << i << ": ";
    //     for (int j : e[i].list_r()) cout << j << " ";
    //     cout << endl;
    // }

    pick_path(0);
    cout << final_res.size() << endl;
    print_res();
}
