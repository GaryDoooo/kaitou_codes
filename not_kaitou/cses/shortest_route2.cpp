#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d[505][505];
int n, m, t, a, b, c, in_q[505];  //, q[2123456], head, tail, j;
// set<int> e[505];
priority_queue<pair<ll, int>> q;
#define len first
#define to second

int main() {
    scanf("%d%d%d", &n, &m, &t);
    memset(d, 127, sizeof(d));
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        d[b][a] = d[a][b] = min((ll)c, d[a][b]);
        // e[b].insert(a), e[a].insert(b);
    }
    for (int i = 1; i < n; i++) {
        // head = 1, tail = 0;
        // q.clear();
        // q.insert({0, i});
        d[i][i] = 0;
        memset(in_q, 1, sizeof(in_q));
        // for (int j : e[i]) {
        multiset<pair<ll, int>> s;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            s.insert({d[i][j], j});
            if (d[i][j] < 1e18) {
                in_q[j] = 1;
                // q[++tail] = j;
                q.push({-d[i][j], j});
            }
        }
        // while (head <= tail) {
        while (!q.empty()) {
            // int now = q.begin()->to, j;
            // q.erase(q.begin());
            int now = q.top().to, j;
            q.pop();
            // int now = q[head++];
            if (in_q[now] == 0) continue;
            in_q[now] = 0;
            // for (auto it = e[now].rbegin(); it != e[now].rend(); it++) {
            // if ((j = *it) <= i) break;
            for (auto it = s.rbegin(); it != s.rend(); it++) {
                if (d[i][now] >= it->len) break;
                j = it->to;
                if (d[i][j] > d[i][now] + d[now][j]) {
                    ll d_old = d[i][j];
                    d[j][i] = d[i][j] = d[i][now] + d[now][j];
                    // e[i].insert(j), e[j].insert(i);
                    // if (!in_q[j])
                    in_q[j] = 1;
                    // q.erase(q.lower_bound({d_old, j}));
                    q.push({-d[i][j], j});
                    // if (in_q[j] == 1)
                    //     continue;
                    // else if (in_q[j] == 0) {
                    //     in_q[j]   = 1;
                    //     q[--head] = j;
                    // } else {
                    //     in_q[j]   = 1;
                    //     q[++tail] = j;
                    // }
                }
            }
        }
        // for (int j = 1; j <= n; j++) e[j].erase(i);
    }
    while (t--) {
        scanf("%d%d", &a, &b);
        if (d[a][b] < 1e18)
            printf("%lld\n", d[a][b]);
        else
            puts("-1");
    }
}

