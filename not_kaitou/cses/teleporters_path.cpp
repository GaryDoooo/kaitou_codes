#include <bits/stdc++.h>
using namespace std;
int n, m, e[212345], nxt[212345], head[112345];
int in_d[112345], out_d[112345], vis[212345], in_q[112345];
int res[212345], r_nxt[212345], r_cnt, r_head;
int node_vis[112345];

int get_nxt(int x) {
    int visted_candidate = 0; 
    int *p               = head + x;
    do {
        int i = *p;
        if (!vis[i]) {
            if (node_vis[e[i]]) {
                visted_candidate = i;
                p                = nxt + i;
            } else {
                *p     = nxt[i];
                vis[i] = 1;
                return e[i];
            }
        } else {
            *p = nxt[i];
            p  = nxt + i;
        }
    } while (*p);
    vis[visted_candidate] = 1;
    return e[visted_candidate];
}

pair<int, int> trip(int start, int end) {
    int h = r_cnt + 1, t, x = start, p = 0, nxt_x;  //, cnt = 0;
    node_vis[x] = 1;
    do {
        nxt_x = get_nxt(x);
        out_d[x]--;
        res[++r_cnt] = nxt_x;
        if (p > 0) r_nxt[p] = r_cnt;
        p           = r_cnt;
        x           = nxt_x;
        node_vis[x] = 1;
    } while (x != end);
    t = r_cnt;
    for (int i = h; i; i = r_nxt[i])
        if (out_d[res[i]]) {
            pair<int, int> tmp = trip(res[i], res[i]);
            int nxt_i          = r_nxt[i];
            r_nxt[i]           = tmp.first;
            i                  = tmp.second;
            r_nxt[i] = nxt_i;
            if (nxt_i == 0) t = i;
        }
    if (out_d[start]) {
        pair<int, int> tmp = trip(start, start);
        int prev_h        = h;
        h                 = tmp.first;
        r_nxt[tmp.second] = prev_h;
    }
    return make_pair(h, t);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[i]    = b;
        nxt[i]  = head[a];
        head[a] = i;
        out_d[a]++;
        in_d[b]++;
    }
    for (int i = 2; i < n; i++)
        if (in_d[i] != out_d[i]) {
            printf("IMPOSSIBLE");
            return 0;
        }
    if (in_d[1] + 1 != out_d[1] or in_d[n] - 1 != out_d[n]) {
        printf("IMPOSSIBLE");
        return 0;
    }
    queue<int> q;
    q.push(1);
    in_q[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            vis[i] = 1;
            if (in_q[e[i]]) continue;
            in_q[e[i]] = 1;
            q.push(e[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (vis[i]) continue;
        printf("IMPOSSIBLE");
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    pair<int, int> r = trip(1, n);
    printf("1 ");
    for (int i = r.first; i; i = r_nxt[i]) printf("%d ", res[i]);
}
