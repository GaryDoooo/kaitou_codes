#include <bits/stdc++.h>
using namespace std;
int n, m, vis[212345], degree[212345];
long long mask = (1 << 17) - 1;
int node[412345], nxt[412345], cnt;
long long edge[412345];
int e_nxt[412345], head[112345], e_cnt;

long long next_step(int from) {
    for (int i = head[from], prev = 0; i; prev = i, i = e_nxt[i]) {
        if (prev)
            e_nxt[prev] = e_nxt[i];
        else
            head[from] = e_nxt[i];
        if (vis[edge[i] >> 17] == 0) return edge[i];
    }
}

pair<int, int> round_trip(int from, int first_trip_from_here) {
    int head = cnt + 1, prev = 0;
    int to, e_i;
    to = from;
    while (to != from or head > cnt) {
        node[++cnt] = to;
        if (prev) nxt[prev] = cnt;
        int now     = to;
        long long i = next_step(now);
        to = i & mask, e_i = i >> 17;
        degree[to]--;
        degree[now]--;
        vis[e_i] = 1;
        prev     = cnt;
    }
    int tail = cnt;
    prev     = 0;
    for (int i = head; i; prev = i, i = nxt[i]) {
        if (node[i] == from and first_trip_from_here == 0) {
            continue;
        }
        while (degree[node[i]]) {
            pair<int, int> chain = round_trip(node[i], node[i] != from);
            if (prev)
                nxt[prev] = chain.first;
            else
                head = chain.first;
            nxt[chain.second] = i;
            prev              = chain.second;
        }
    }
    return make_pair(head, tail);
}

int main() {
    scanf("%d %d", &n, &m);
    for (long long i = 1; i <= m; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        edge[++e_cnt] = (i << 17) + b;
        e_nxt[e_cnt]  = head[a];
        head[a]       = e_cnt;

        edge[++e_cnt] = (i << 17) + a;
        e_nxt[e_cnt]  = head[b];
        head[b]       = e_cnt;
        degree[a]++;
        degree[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] & 1 or degree[1] == 0) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    //
    // find out step count from 1
    //
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j = head[x]; j; j = e_nxt[j]) {
            long long i = edge[j];
            int to      = i & mask;
            int e_i     = i >> 17;
            if (vis[e_i]) continue;
            vis[e_i] = 1;
            q.push(to);
        }
    }
    for (int i = 1; i <= m; i++)
        if (vis[i] == 0) {
            puts("IMPOSSIBLE");
            return 0;
        }
    memset(vis, 0, sizeof(vis));
    pair<int, int> res = round_trip(1, 1);
    for (int i = res.first; i; i = nxt[i]) printf("%d ", node[i]);
    puts("1");
}
