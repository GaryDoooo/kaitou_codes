#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d[505][505];
int n, m, t, a, b, c, in_q[505];
priority_queue<pair<ll, int>> q;
#define len first
#define to second
struct ToDo {
    int idx;
    ll from, to;
};

int main() {
    scanf("%d%d%d", &n, &m, &t);
    memset(d, 127, sizeof(d));
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        d[b][a] = d[a][b] = min((ll)c, d[a][b]);
    }
    for (int i = 1; i < n; i++) {
        d[i][i] = 0;
        memset(in_q, 1, sizeof(in_q));
        multiset<pair<ll, int>> s;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            s.insert({d[i][j], j});
            if (d[i][j] < 1e18) {
                in_q[j] = 1;
                q.push({-d[i][j], j});
            }
        }
        while (!q.empty()) {
            int now = q.top().to, j;
            q.pop();
            if (in_q[now] == 0) continue;
            in_q[now] = 0;
            vector<ToDo> todo;
            for (auto it = s.rbegin(); it != s.rend(); it++) {
                if (d[i][now] >= it->len) break;
                j = it->to;
                if (d[i][j] > d[i][now] + d[now][j]) {
                    ll old_d = d[i][j];
                    d[j][i] = d[i][j] = d[i][now] + d[now][j];
                    in_q[j]           = 1;
                    q.push({-d[i][j], j});
                    todo.push_back({j, old_d, d[j][i]});
                }
            }
            for (auto j : todo) {
                s.erase(s.lower_bound({j.from, j.idx}));
                s.insert({j.to, j.idx});
            }
        }
    }
    while (t--) {
        scanf("%d%d", &a, &b);
        if (a == b)
            puts("0");
        else if (d[a][b] < 1e18)
            printf("%lld\n", d[a][b]);
        else
            puts("-1");
    }
}

