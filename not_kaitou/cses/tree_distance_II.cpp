#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> res[212345];
vector<int> e[212345];
int cnt[212345];
long long result[212345];

long long sub_tree_sum(int x, int fa) {
    long long s = 0;
    int c       = 1;
    for (int leaf : e[x]) {
        if (leaf == fa) {
            res[x].push_back(-1);
            continue;
        }
        long long tmp = sub_tree_sum(leaf, x);
        res[x].push_back(tmp);
        s += tmp + cnt[leaf];
        c += cnt[leaf];
    }
    cnt[x]           = c;
    return result[x] = s;
}

void fill_root(int x, int fa, long long fa_sum, int fa_cnt) {
    result[x]     = result[x] + fa_sum + fa_cnt;
    int total_cnt = fa_cnt + cnt[x];
    // cnt[x] += fa_cnt;
    for (int i = 0; i < e[x].size(); i++) {
        if (e[x][i] == fa) continue;
        fill_root(e[x][i], x, result[x] - res[x][i] - cnt[e[x][i]],
                  total_cnt - cnt[e[x][i]]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    sub_tree_sum(1, 0);
    fill_root(1, 0, 0, 0);
    // for (int i = 1; i <= n; i++) cout << cnt[i] << endl;
    for (int i = 1; i <= n; i++) printf("%lld ", result[i]);
}
