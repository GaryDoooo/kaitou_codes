#include <bits/stdc++.h>
#define MOD 31011
using namespace std;
struct edge {
    int n1, n2, len;
};
bool operator<(const edge& a, const edge& b) { return a.len < b.len; }
int n, m, done[1005], head, root[105], cnt, done_rt[105];
edge e[10005];
int get_root(int i) {
    while (i != root[i]) i = root[i];
    return i;
}
void combine(int a, int b) {
    int a_root = get_root(a), b_root = get_root(b);
    if (a_root > b_root)
        root[a_root] = b_root;
    else
        root[b_root] = a_root;
}

// void dfs(int rt_idx, vector<int> const& trees, vector<int> const& edges,
//          int lvl) {
//     if (lvl > trees.size()) {
//         for (int i = 0; i < m; i++)
//             if (done[i]) cout << i << " ";
//         cout << "over" << endl;
//         cnt++;
//         return;
//     }
//     bool found      = false;
//     done_rt[rt_idx] = 1;
//     for (int edge : edges) {
//         int r1 = get_root(e[edge].n1), r2 = get_root(e[edge].n2);
//         if (r2 == rt_idx) swap(r1, r2);
//         if (r1 == rt_idx and !done[edge] and !done_rt[r2]) {
//             found      = true;
//             done[edge] = 1;
//             dfs(r2, trees, edges, lvl + 1);
//             done[edge] = 0;
//         }
//     }
//     if (!found) {
//         int next_rt = -1;
//         for (int rt : trees)
//             if (!done_rt[rt]) {
//                 next_rt = rt;
//                 break;
//             }
//         if (next_rt == -1) {
//             for (int i = 0; i < m; i++)
//                 if (done[i]) cout << i << " ";
//             cout << endl;
//             cnt++;
//             done_rt[rt_idx] = 0;
//             return;
//         }
//         dfs(next_rt, trees, edges, lvl + 1);
//     }
//     done_rt[rt_idx] = 0;
// }
int cnt_trees() {
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(get_root(i));
    return s.size();
}

int try_connect(vector<int> const& edges) {
    int root_backup[105];
    memcpy(root_backup, root, sizeof root);
    for (int i : edges) combine(e[i].n1, e[i].n2);
    int res = cnt_trees();
    memcpy(root, root_backup, sizeof root);
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d%d", &e[i].n1, &e[i].n2, &e[i].len);
    sort(e, e + m);
    for (int i = 1; i <= n; i++) root[i] = i;
    // for (int i = 0; i < m; i++) {
    //     cout << i << " " << e[i].n1 << " " << e[i].n2 << endl;
    // }
    // cout << e[m - 1].len << endl;
    int res = 1, node_included = 0;
    while (head < m) {
        int tail = head;
        while (e[tail].len == e[tail + 1].len) tail++;
        // set<int> trees;
        vector<int> edges;
        for (int i = head; i <= tail; i++) {
            int r1 = get_root(e[i].n1), r2 = get_root(e[i].n2);
            if (r1 != r2) {
                edges.push_back(i);
                // trees.insert(r1);
                // trees.insert(r2);
            }
        }
        head = tail + 1;
        if (edges.size() == 0) continue;
        //         if (!done[e[i].n1]) s.insert(e[i].n1);
        //         if (!done[e[i].n2]) s.insert(e[i].n2);
        //     }
        // int trees_to_combine = s.size();
        // memset(done, 0, sizeof done);
        // memset(done_rt, 0, sizeof done_rt);
        // vector<int> trees_dfs(trees.begin(), trees.end());
        // for (int i : edges) cout << i << " ";
        // cout << "edges" << endl;
        cnt = 1;
        // dfs(trees_dfs[0], trees_dfs, edges, 1);
        int target_tree_cnt = try_connect(edges), count[20];
        // cout << "target tree cnt: " << target_tree_cnt << endl;
        memset(count, 0, sizeof count);
        //     if (node_added_in_this_lvl == 0) {
        //         head = tail + 1;
        //         continue;
        //     }
        //     int edge_need_this_lvl = node_added_in_this_lvl - (node_included
        // == 0); int t, cnt = 0;
        for (int i = 1; i < (1 << edges.size()); i++) {
            vector<int> edge_picks;
            for (int j = 0; j < edges.size(); j++)
                if ((i >> j) & 1) edge_picks.push_back(edges[j]);
            int tree_cnt = try_connect(edge_picks);
            if (tree_cnt == target_tree_cnt) count[edge_picks.size()]++;
            // for (int j : edge_picks) cout << j << " ";
            // cout << "cnt: " << tree_cnt << endl;
        }
        for (int i = 0; i < edges.size(); i++)
            if (count[i] > 0) {
                cnt = count[i];
                break;
            }
        //     1;
        //          i < (1 << (tail - head + 1)); i++) {
        //         set<int> ss;
        //         int cnt2 = 0;
        //         for (int j = 0; j <= tail - head; j++) cnt2 += (i >> j) & 1;
        //         if (cnt2 != edge_need_this_lvl) continue;
        //         // cout << cnt2 << " " << edge_need_this_lvl << endl;
        //         for (int j = 0; j <= tail - head; j++) {
        //             if ((i >> j) & 1) {
        //                 t = head + j;
        //                 if (!done[e[t].n1]) ss.insert(e[t].n1);
        //                 if (!done[e[t].n2]) ss.insert(e[t].n2);
        //             }
        //         }
        //         cnt += (ss.size() == node_added_in_this_lvl);
        //         // cout << i << " " << ss.size() << " " << head << " " <<
        //         tail <<
        //         // endl;
        //     }
        res = (res * cnt) % MOD;
        // for (int i : trees) combine(*trees.begin(), i);
        for (int i : edges) combine(e[i].n1, e[i].n2);
        if (target_tree_cnt == 1) break;
        // cout << "roots cnt " << cnt_trees() << " res" << res << "cnt" << cnt
        // << endl;
        //     node_included += node_added_in_this_lvl;
        //     if (node_included == n) break;
        //     for (int i : s) done[i] = 1;
        // head = tail + 1;
    }
    if (cnt_trees() == 1)
        printf("%d\n", res);
    else
        puts("0");
}

