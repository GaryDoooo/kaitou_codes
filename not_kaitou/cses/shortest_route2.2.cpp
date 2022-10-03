#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d[505][505], c, dd[505][505];
int n, m, t, a, b, in_q[505];
set<int> e[505];
multiset<pair<ll, int>> q;
#define len first
#define to second
int g[505];

int get_root(int x) {
    int in = x;
    while (g[x]) x = g[x];
    if (in != x) g[in] = x;
    return x;
}

struct edge {
    ll len;
    int from, to;
    friend bool operator<(const edge& a, const edge& b) {
        return tie(a.len, a.from, a.to) < tie(b.len, b.from, b.to);
    }
};

edge edges[250005];

ll shortest(int i, int y) {
    q.clear();
    d[i][i] = 0;
    memset(in_q, 0, sizeof(in_q));
    for (int j : e[i]) {
        // if (i == 6 and y == 7) cout << j << " ";
        in_q[j] = 1;
        q.insert({d[i][j], j});
    }
    // cout << endl;
    while (!q.empty()) {
        // if (i == 6 and y == 7) {
        //     for (auto j : q) cout << j.len << "," << j.to << " ";
        //     cout << endl;
        // }
        int now = q.begin()->to;
        if (now == y) return d[i][y];
        q.erase(q.begin());
        in_q[now] = 0;
        for (int j : e[now]) {
            // if (i == 6 and y == 7 and now == 8) cout << j << " ";
            if (d[i][j] >= d[i][now] + d[now][j]) {
                ll d_old = d[i][j];
                d[j][i] = d[i][j] = d[i][now] + d[now][j];
                // if ((j == 3 and i == 5) or (j == 5 and i == 3)) {
                //     cout << " add 3 5 " << i << "to" << now << "to" << j << "
                //     "
                //          << d[i][now] << " " << d[now][j] << endl;
                // }
                if (!in_q[j])
                    in_q[j] = 1;
                else
                    q.erase(q.lower_bound({d_old, j}));
                q.insert({d[i][j], j});
            }
        }
    }
    return (ll)1e13;
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    int mm = m;
    memset(d, 1, sizeof(d));
    memset(dd, 1, sizeof(dd));
    while (m--) {
        scanf("%d%d%lld", &a, &b, &c);
        edges[m] = {c, a, b};
    }
    sort(edges, edges + mm);
    for (int i = 0; i < mm; i++) {
        a = edges[i].from, b = edges[i].to, c = edges[i].len;
        int a_root = get_root(a), b_root = get_root(b);
        if (a_root != b_root) {
            dd[b][a] = dd[a][b] = d[b][a] = d[a][b] = c;
            e[b].insert(a), e[a].insert(b);
            g[a_root] = b_root;
            // cout << "add " << a << " to " << b << " combine " << a_root << "
            // "
            //      << b_root << endl;
        } else {
            // cout << "try add " << a << " to " << b << "=" << c << " with
            // "
            // << d[b][a] << endl;
            if (c < d[b][a]) {
                ll sht = shortest(a, b);
                // cout << "get shortest " << a << " to " << b << " is" << sht
                //      << endl;
                if (c < sht) {
                    dd[b][a] = dd[a][b] = d[b][a] = d[a][b] = c;
                    e[b].insert(a), e[a].insert(b);
                    // cout << "add " << a << " to " << b << endl;
                }
            }
        }
    }
    swap(dd, d);
    for (int i = 1; i < n; i++) {
        q.clear();
        // q.insert({0, i});
        d[i][i] = 0;
        memset(in_q, 0, sizeof(in_q));
        for (int j : e[i]) {
            in_q[j] = 1;
            q.insert({d[i][j], j});
        }
        while (!q.empty()) {
            int now = q.begin()->to, j;
            q.erase(q.begin());
            in_q[now] = 0;
            for (auto it = e[now].rbegin(); it != e[now].rend(); it++) {
                if ((j = *it) <= i) break;
                if (d[i][j] > d[i][now] + d[now][j]) {
                    ll d_old = d[i][j];
                    d[j][i] = d[i][j] = d[i][now] + d[now][j];
                    // e[i].insert(j), e[j].insert(i);
                    if (!in_q[j]) {
                        in_q[j] = 1;
                        q.insert({d[i][j], j});
                    } else {
                        q.erase(q.lower_bound({d_old, j}));
                        q.insert({d[i][j], j});
                    }
                }
            }
        }
    }
    while (t--) {
        scanf("%d%d", &a, &b);
        // if (d[a][b] < 1e13)
        //     printf("%lld\n", d[a][b]);
        // else
        //     puts("-1");
    }
}

