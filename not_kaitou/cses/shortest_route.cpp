#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll d[112345];
int n, a, b, c, m, in_q[112345], tail[112345], e_cnt;
typedef pair<int, int> pii;
#define len first
#define to second
vector<pii> e[112345];
// queue<int> q;
multiset<pair<ll, int>> q;

// struct edge {
//     int to, len, fa, son;
// } e[212345];
//
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back({c, b});
        // e[++e_cnt]    = {b, c, 0, tail[a]};
        // e[tail[a]].fa = e_cnt;
        // tail[a]       = e_cnt;
    }
    // q.push(1);
    memset(d, 127, sizeof(d));
    d[1] = 0;
    q.insert({0, 1});
    while (!q.empty()) {
        // int now = q.front();
        // q.pop();
        int now = q.begin()->to;
        q.erase(q.begin());
        in_q[now] = 0;
        // for (auto i = e[tail[now]]; i.len; i = e[i.son]) {
        for (auto i : e[now]) {
            if (d[i.to] > d[now] + i.len) {
                d[i.to] = d[now] + i.len;
                if (!in_q[i.to]) {
                    in_q[i.to] = 1;
                    q.insert({d[i.to], i.to});
                    // q.push(i.to);
                }
            }
            // else if (i.len >= d[i.to]) {
            //     if (i.fa) {
            //         e[i.fa].son = i.son;
            //         e[i.son].fa = i.fa;
            //     } else {
            //         e[i.son].fa = 0;
            //         tail[now]   = i.son;
            //     }
            // }
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", d[i]);
    puts("");
}
