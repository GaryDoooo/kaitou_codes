#include <bits/stdc++.h>
#define BASE 100005
using namespace std;

int n, m, k[212345], visited[212345];
int q[212345], q_tail, k_first_in_queue[212345], k_last_in_queue[212345];
int edge[212345], nxt[212345], head[212345], e_cnt;
int res[212345];  //, result[212345];
unordered_set<int> ke[112345], ke_reverse[112345];
long long coin[112345];

int get_root(int x) {
    int xx = x;
    while (k[xx]) xx = k[xx];
    if (x != xx) k[x] = xx;
    return xx;
}

void combine_root(int a, int b) {
    int ar = get_root(a), br = get_root(b);
    if (ar == br) return;
    k[br] = k[b] = ar;
}

void dfs(int x) {
    visited[x]  = 1;
    q[++q_tail] = x;
    int xr      = get_root(x);
    if (k_first_in_queue[xr] == 0) k_first_in_queue[xr] = q_tail;
    k_last_in_queue[xr] = q_tail;
    for (int e = head[x]; e; e = nxt[e]) {
        int to = edge[e];
        if (visited[to]) {
            int to_r = get_root(to);
            if (to_r == xr) continue;
            if (k_first_in_queue[to_r]) {
                for (int i = k_last_in_queue[to_r] + 1; i <= q_tail; i++) {
                    combine_root(to_r, q[i]);
                }
            }
            k_last_in_queue[to_r] = q_tail;
        } else {
            dfs(to);
        }
    }
    xr = get_root(x);
    if (k_first_in_queue[xr] == q_tail)
        k_first_in_queue[xr] = k_last_in_queue[xr] = 0;
    else
        k_last_in_queue[xr]--;
    q_tail--;
}

void convert_edge(int x) {
    int xr = res[x];
    for (int e = head[x]; e; e = nxt[e]) {
        int to_r = res[edge[e]];
        if (to_r == xr) continue;
        ke[xr].insert(to_r);
        ke_reverse[to_r].insert(xr);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", coin + i);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        edge[++e_cnt] = b;
        nxt[e_cnt]    = head[a];
        head[a]       = e_cnt;
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs(i);
    long long kc[112345], k_cnt  = 0;
    int k_cnvt[112345], cnvt_cnt = 0;
    memset(k_cnvt, 0, sizeof(k_cnvt));
    memset(kc, 0, sizeof(kc));
    for (int i = 1; i <= n; i++) {
        int ri = get_root(i);
        if (k_cnvt[ri] == 0) k_cnvt[ri] = ++cnvt_cnt;
        res[i] = k_cnvt[ri];
        kc[res[i]] += coin[i];
    }
    for (int i = 1; i <= n; i++) convert_edge(i);
    int out_cnt[112345];
    queue<int> q;
    memset(out_cnt, 0, sizeof(out_cnt));
    for (int i = 1; i <= cnvt_cnt; i++) {
        if ((out_cnt[i] = ke[i].size()) == 0) q.push(i);
        // cout << i << ":" << kc[i] << " ";
        // for (auto j : ke[i]) cout << j << " ";
        // cout << endl;
    }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        out_cnt[i] = -1;
        for (int from : ke_reverse[i]) {
            // kc[from] += kc[i];
            if (--out_cnt[from] == 0) {
                q.push(from);
                long long best_exit = 0;
                for (auto to : ke[from]) best_exit = max(best_exit, kc[to]);
                kc[from] += best_exit;
            }
        }
    }
    long long res = 0;
    for (int i = 1; i <= cnvt_cnt; i++) res = max(res, kc[i]);
    cout << res << endl;
}

