#include <bits/stdc++.h>
using namespace std;

struct space_time {
    long long x, y, t;
    bool operator<(const space_time &b) { return t < b.t; }
};

long long dist(const space_time &a, const space_time &b) {
    return (long long)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n, m, res;
vector<space_time> g;
main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        space_time s;
        scanf("%lld %lld %lld", &s.x, &s.y, &s.t);
        g.push_back(s);
    }
    sort(g.begin(), g.end());
    while (m--) {
        space_time s;
        scanf("%lld %lld %lld", &s.x, &s.y, &s.t);
        auto it = lower_bound(g.begin(), g.end(), s);
        if (it == g.end()) {
            if (dist(g.back(), s) > (s.t - g.back().t) * (s.t - g.back().t))
                res++;
        } else if (it == g.begin()) {
            if (dist(g[0], s) > (g[0].t - s.t) * (g[0].t - s.t)) {
                res++;
            }
        } else {
            int i = abs(distance(g.begin(), it));
            if (dist(g[i], s) > (g[i].t - s.t) * (g[i].t - s.t)) {
                res++;
            } else if (dist(g[i - 1], s) >
                       (s.t - g[i - 1].t) * (s.t - g[i - 1].t)) {
                res++;
            }
        }
    }
    cout << res << endl;
}

