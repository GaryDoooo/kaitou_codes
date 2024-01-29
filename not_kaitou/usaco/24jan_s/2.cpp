#include <bits/stdc++.h>
using namespace std;
int n, p[112345], fa[112345], vis[112345], have_num_of_potion[112345],
    potion_num_on_backtrace[112345];
vector<int> edges[112345];
vector<int> leaf;

void dfs_make_tree(int father, int x) {
    vis[x]      = 1;
    fa[x]       = father;
    int out_cnt = 0;
    for (int nxt : edges[x]) {
        // cout << nxt << endl;
        if (vis[nxt]) continue;
        dfs_make_tree(x, nxt);
        out_cnt++;
    }
    if (out_cnt == 0)  // it's a leaf
        leaf.push_back(x);
}

int back_trace_from_leaf(int x) {
    while (x) {
        if (have_num_of_potion[x]) {
            have_num_of_potion[x]--;
            return 1;
        }
        if (potion_num_on_backtrace[x] == 0) return 0;
        x = fa[x];
    }
    return 0;
}

void add_potion_of_backtrace(int father, int x, int ttl) {
    int out_cnt                = 0;
    potion_num_on_backtrace[x] = ttl;
    for (int nxt : edges[x]) {
        if (father == nxt) continue;
        add_potion_of_backtrace(x, nxt, ttl + have_num_of_potion[x]);
        out_cnt++;
    }
}

pair<int, int> count_sub_tree(int father, int x)
// first is how many potions got
// second is how many leaves available
{
    pair<int, int> res;
    int num_potion = 0, num_leaves = 0, out_cnt = 0;
    for (int nxt : edges[x]) {
        if (father == nxt) continue;
        // if (vis[x]) continue;
        // cout << nxt << endl;
        out_cnt++;
        pair<int, int> r = count_sub_tree(x, nxt);
        num_potion += r.first;
        num_leaves += r.second;
    }
    if (out_cnt == 0)  // it's a leaf
    {
        if (have_num_of_potion[x])
            num_potion = 1;
        else
            num_leaves = 1;
    } else {
        if (have_num_of_potion[x]) {
            if (have_num_of_potion[x] >= num_leaves) {
                num_leaves = 0;
                num_potion += num_leaves;
            } else {
                num_leaves -= have_num_of_potion[x];
                num_potion += have_num_of_potion[x];
            }
        }
    }
    res.first  = num_potion;
    res.second = num_leaves;
    // cout << x << " " << res.first << " " << res.second << endl;
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs_make_tree(0, 1);
    for (int i = 0; i < leaf.size(); i++) have_num_of_potion[p[i]]++;
    // add_potion_of_backtrace(0, 1, 0);
    int res = 0;
    // if (leaf.size() > 10000 and leaf.size() < 40000) {
    // memset(vis, 0, sizeof(vis));
    pair<int, int> r = count_sub_tree(0, 1);
    res              = r.first;
    // } else {
    // for (int l : leaf) {
    // res += back_trace_from_leaf(l);
    // }
    // }
    cout << res << endl;
}
