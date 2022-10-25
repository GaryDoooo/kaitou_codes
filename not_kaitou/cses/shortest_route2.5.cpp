#include <bits/stdc++.h>
// #define dis first
#define idx second
using namespace std;
using ll = long long;
int n, m, t, u, v, w, in_q[505];
ll d[505][505];
vector<int> edges[505];
// struct node {
//     ll dis;
//     int idx;
//     friend bool operator<(const node& a, const node& b) {
//         return a.dis > b.dis;
//     }
// };
// priority_queue<node> q;
multiset<pair<ll, int>> q;
// multiset并不慢，
int main() {
    memset(d, 1, sizeof(d));
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        if (d[u][v] > 1e9) edges[u].push_back(v), edges[v].push_back(u);
        d[u][v] = d[v][u] = min(d[u][v], (ll)w);
    }
    for (int i = 1; i <= n; i++) sort(edges[i].begin(), edges[i].end());
    for (int s = 1; s < n; s++) {
        memset(in_q, 0, sizeof(in_q));
        for (int i = 1; i <= n; i++) in_q[i] = 1, q.insert({d[s][i], i});
        while (q.size()) {
            int u = q.begin()->idx;
            q.erase(q.begin());
            // u = q.top().idx, q.pop();
            if (!in_q[u]) continue;
            in_q[u] = 0;
            for (auto it = edges[u].rbegin(); it != edges[u].rend(); ++it) {
                if ((v = *it) < s) break;
                if (in_q[v])
                    if (d[s][v] > d[s][u] + d[u][v]) {
                        // auto it = q.lower_bound({d[s][v], v});
                        d[s][v] = d[v][s] = d[s][u] + d[u][v];
                        // q.erase(it);
                        q.insert({d[s][v], v});
                    }
            }
        }
    }
    while (t--) {
        scanf("%d%d", &u, &v);
        if (d[u][v] > 1e13)
            puts("-1");
        else
            printf("%lld\n", d[u][v]);
    }
}
