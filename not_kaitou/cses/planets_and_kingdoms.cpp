#include <bits/stdc++.h>
using namespace std;
int n, m, k[112345], visited[112345];
int edge[212345], next_edge[212345], head[112345];  //,e_cnt;//, tail[112345];
// vector<vector<int>> loops;
int q[112345], q_tail, k_first_in_queue[112345], k_last_in_queue[112345];

int get_root(int x) {
    int xx = x;
    while (k[xx]) xx = k[xx];
    if (x != xx) k[x] = xx;
    return xx;
}

void combine_root(int a, int b) {
    int ar = get_root(a), br = get_root(b);
    if (ar == br) return;
    // if (ar > br) swap(ar, br), swap(a, b);
    k[br] = k[b] = ar;
    // next_edge[tail[br]] = head[ar];
    // head[ar]            = head[br];
}

void dfs(int x) {
    visited[x]  = 1;
    q[++q_tail] = x;
    int xr      = get_root(x);
    if (k_first_in_queue[xr] == 0) k_first_in_queue[xr] = q_tail;
    k_last_in_queue[xr] = q_tail;
    for (int e = head[x]; e; e = next_edge[e]) {
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

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        edge[i]      = to;
        next_edge[i] = head[from];
        head[from]   = i;
    }
    // puts("done input");
    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs(i);
    // puts("done dfs");
    int cnt = 0, res[112345], root_cnvt[112345];
    for (int i = 1; i <= n; i++) {
        int xr = get_root(i);
        if (root_cnvt[xr] == 0) root_cnvt[xr] = ++cnt;
        res[i] = root_cnvt[xr];
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
}
