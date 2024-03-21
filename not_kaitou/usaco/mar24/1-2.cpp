#include <bits/stdc++.h>
using namespace std;
int n, k, idx, vis[312345];
long long t[312345];
priority_queue<pair<long long, long long>> q;
unordered_set<int> e[312345];

void dfs(int x) {
    vis[x] = 1;
    for (int i : e[x]) {
        if (vis[i]) continue;
        dfs(i);
    }
}

void add_edge(int a, int b) {
    e[a].insert(b);
    e[b].insert(a);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", t + i);
    for (long long i = 1; i <= k; i++) q.push(make_pair(-t[i], i));
    idx = k;
    while (q.size()) {
        long long now = q.top().first, farmer = q.top().second, cnt = 1;
        q.pop();
        while (q.top().first == now) {
            add_edge(farmer, q.top().second);
            cnt++;
            q.pop();
        }
        if (idx + cnt <= n) {
            for (int i = 1; i <= cnt; i++)
                q.push(make_pair(now - t[idx + i], farmer));
            idx += cnt;
        } else {
            printf("%lld\n", -now);
            dfs(farmer);
            for (int i = 1; i <= k; i++) printf("%d", vis[i]);
            puts("");
            return 0;
        }
    }
}

