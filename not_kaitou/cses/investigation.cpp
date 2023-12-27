#include <bits/stdc++.h>
#define N 100005
#define M 200005
using namespace std;
using ll      = long long;
const int mod = 1e9 + 7;
int n, m, u, w, v, done[N];
vector<pair<int, int>> e[N];
struct graph_node {
    ll min_d      = 1e18;
    int steps_max = -1, steps_min = 1e9, cnt;
} a[N];
struct queue_node {
    int i;
    ll d;
    friend bool operator<(const queue_node& x, const queue_node& y) {
        return x.d > y.d;
        // return a[x.i].min_d > a[y.i].min_d;
    }
};
priority_queue<queue_node> q;
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
    }
    a[1].min_d     = 0;
    a[1].cnt       = 1;
    a[1].steps_max = a[1].steps_min = 0;
    q.push({1, 0});
    while (q.size()) {
        int u = q.top().i;
        q.pop();
        // cout << u << ": " << a[u].min_d << " " << a[u].cnt << " "
        //      << a[u].steps_max << " " << a[u].steps_min << endl;
        if (u == n) {
            printf("%lld %d %d %d", a[u].min_d, a[u].cnt, a[u].steps_min,
                   a[u].steps_max);
            return 0;
        }
        if (done[u]) continue;
        done[u] = true;
        for (auto edge : e[u]) {
            int v = edge.first;
            ll w  = a[u].min_d + edge.second;
            if (w == a[v].min_d) {
                a[v].cnt       = (a[v].cnt + a[u].cnt) % mod;
                a[v].steps_max = max(a[v].steps_max, a[u].steps_max + 1);
                a[v].steps_min = min(a[v].steps_min, a[u].steps_min + 1);
            } else if (w < a[v].min_d) {
                a[v].min_d     = w;
                a[v].cnt       = a[u].cnt;
                a[v].steps_max = a[u].steps_max + 1;
                a[v].steps_min = a[u].steps_min + 1;
                q.push({v, w});
            }
        }
    }
}
