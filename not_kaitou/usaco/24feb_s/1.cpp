#include <bits/stdc++.h>
using namespace std;
long long t, n, x1;
long long y_1[41234], y2[41234], x2[41234];
long long s[161234];

struct point {
    long long x, y;
    int sign;  // 0 both 1 pos 2 neg
    int taken;
};

void pb(vector<point>& a, long long x, long long y, int sign) {
    point p;
    p.x     = x;
    p.y     = y;
    p.sign  = sign;
    p.taken = 0;
    a.push_back(p);
}

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &n, &x1);
        for (int i = 1; i <= n; i++)
            scanf("%lld %lld %lld", &y_1[i], &y2[i], &x2[i]);  // x2 + i);
        vector<long long> ps, ns;
        for (int i = 1; i <= n * 4; i++) {
            scanf("%lld", &s[i]);
            if (s[i] > 0)
                ps.push_back(s[i]);
            else
                ns.push_back(s[i]);
        }
        if (ps.size() < n or n > ns.size()) {
            puts("-1");
            continue;
        }
        sort(ps.begin(), ps.end());
        sort(ns.begin(), ns.end());
        vector<point> p;
        long long y_max = -1e18, y_min = 1e18;
        for (int i = 1; i <= n; i++) {
            pb(p, x2[i], y_1[i], 1);
            pb(p, x1, y2[i], 0);
            pb(p, x1, y_1[i], 0);
            pb(p, x2[i], y2[i], 2);
        }
        for (int i = 0; i < ns.size(); i++) {
            long long s = ns[i];
            int pick;
            long long ymin = 1e18;
            for (int j = 0; j < p.size(); j++) {
                if (p[j].taken) continue;
                if (p[j].sign == 1) continue;
                long long y0 = p[j].y - s * p[j].x;
                if (y0 < ymin) {
                    pick = j;
                    ymin = y0;
                }
            }
            p[pick].taken = 1;
            cout << ymin << " ";
            y_max = max(y_max, ymin);
            y_min = min(y_min, ymin);
        }
        for (int i = ps.size() - 1; i >= 0; i--) {
            long long s = ps[i];
            int pick;
            long long ymax = -1e18;
            for (int j = 0; j < p.size(); j++) {
                if (p[j].taken) continue;
                if (p[j].sign == 2) continue;
                long long y0 = p[j].y - s * p[j].x;
                if (y0 > ymax) {
                    pick = j;
                    ymax = y0;
                }
            }
            p[pick].taken = 1;
            cout << ymax << " ";
            y_max = max(y_max, ymax);
            y_min = min(y_min, ymax);
        }
        printf("%lld\n", y_max - y_min);
    }
}

//             // ppoints.push_back({x2[i], y1[i]});
//             // ppoints.push_back({x1, y2[i]});
//             // npoints.push_back({x1, y1[i]});
//             // npoints.push_back({x2[i], y2[i]});
//         }
//         sort(ppoints.begin(), ppoints.end(), comparep);
//         sort(npoints.begin(), npoints.end(), comparen);
//         sort(ps.begin(), ps.end());
//         sort(ns.begin(), ns.end());
//         long long max_y = 0, min_y = 1e18;
//         for (int i = 0; i < 2 * n; i++) {
//             cout << ppoints[i].x << " " << ppoints[i].y << " " << ps[i] <<
//             endl; min_y = min(min_y, ppoints[i].y - ps[i] * ppoints[i].x);
//         }
//         for (int i = 2 * n - 1; i >= 0; i--) {
//             cout << npoints[i].x << " " << npoints[i].y << " " << ns[i] <<
//             endl; max_y = max(max_y, npoints[i].y - ns[i] * npoints[i].x);
//         }
//         printf("%lld\n", max_y - min_y);
//     }
// }
//
