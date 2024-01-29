#include <bits/stdc++.h>
using namespace std;
int n, p[112345], fa[112345], have_num_of_potion[112345];
vector<int> edges[112345];
vector<int> leaf;
int have_ttl_leaf[112345], got_potions[112345], out_d[112345];

void dfs_make_tree(int father, int x) {
    fa[x]       = father;
    int out_cnt = 0;
    for (int nxt : edges[x]) {
        if (father == nxt) continue;
        dfs_make_tree(x, nxt);
        out_cnt++;
    }
    out_d[x] = out_cnt;
    if (out_cnt == 0)  // it's a leaf
        leaf.push_back(x);
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
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (out_d[i] == 0) {
            q.push(i);
            have_ttl_leaf[i] = 1;
        }
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (have_num_of_potion[x]) {
            if (have_ttl_leaf[x] > have_num_of_potion[x]) {
                have_ttl_leaf[x] -= have_num_of_potion[x];
                got_potions[x] = have_num_of_potion[x];
            } else {
                got_potions[x]   = have_ttl_leaf[x];
                have_ttl_leaf[x] = 0;
            }
        }
        out_d[fa[x]]--;
        have_ttl_leaf[fa[x]] += have_ttl_leaf[x];
        if (out_d[fa[x]] == 0) q.push(fa[x]);
    }
    for (int i = 1; i <= n; i++) res += got_potions[i];
    cout << res << endl;
}
