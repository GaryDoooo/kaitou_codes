#include <bits/stdc++.h>
using namespace std;
int n, p[112345], fa[112345], have_num_of_potion[112345];
vector<int> edges[112345];
vector<int> leaf;

void dfs_make_tree(int father, int x) {
    fa[x]       = father;
    int out_cnt = 0;
    for (int nxt : edges[x]) {
        if (father == nxt) continue;
        dfs_make_tree(x, nxt);
        out_cnt++;
    }
    if (out_cnt == 0)  // it's a leaf
        leaf.push_back(x);
}

pair<int, int> count_sub_tree(int father, int x)
// first is how many potions got
// second is how many leaves available
{
    pair<int, int> res;
    int num_potion = 0, num_leaves = 0, out_cnt = 0;
    for (int nxt : edges[x]) {
        if (father == nxt) continue;
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
    int res = 0;
    pair<int, int> r = count_sub_tree(0, 1);
    res              = r.first;
    cout << res << endl;
}
