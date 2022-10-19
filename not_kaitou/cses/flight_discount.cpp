#include <bits/stdc++.h>
#define to second
#define dis first
using namespace std;
using ll = long long;
int n, m, u, v, w, done[112345];
// struct node {
//     ll ttl_cost, max_cost;
//     int idx;
//     bitset<100001> done;
//     friend bool operator<(const node& a, const node& b) {
//         return a.ttl_cost > b.ttl_cost;
//     }
// };
vector<pair<int, int>> in_e[112345], out_e[112345];
priority_queue<pair<ll, int>> q;
// priority_queue<node> q;
ll d1[112345], dn[112345], res = 1e18;
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        out_e[u].push_back(make_pair(w, v));
        in_e[v].push_back(make_pair(w, u));
    }
    for (int s = 1; s <= n; s += n - 1) {
        memset(done, 0, sizeof(done));
        done[s] = 1;
        memset(d1, 1, sizeof(d1));
        d1[s] = 0;
        for (auto i : out_e[s]) d1[i.to] = i.dis, q.push({-i.dis, i.to});
        while (q.size()) {
            u = q.top().to;
            q.pop();
            if (done[u]) continue;
            done[u] = 1;
            for (auto i : out_e[u]) {
                if (done[i.to]) continue;
                ll dis = d1[u] + i.dis;
                if (dis < d1[i.to]) {
                    d1[i.to] = dis;
                    q.push({-dis, i.to});
                }
            }
        }
        swap(d1, dn);
        swap(in_e, out_e);
    }
    for (int s = 1; s < n; s++)
        for (auto i : out_e[s]) res = min(res, d1[s] + dn[i.to] + (i.dis >> 1));
    cout << res << endl;
}
