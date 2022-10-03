#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
struct point {
    ll x, y;
};  // a[212345];
bool operator<(const point& a, const point& b) { return a.x < b.x; }
int n;
ll sqrt_res = 4e9;
ull res;
int main() {
    res = ~res;
    // cout << res;
    scanf("%d", &n);
    vector<point> a(n);
    // unordered_set<int> xs, ys;
    ll minx = 2e9, maxx = -2e9, miny = 2e9, maxy = -2e9;  //, maxy;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        minx = min(minx, a[i].x);
        maxx = max(maxx, a[i].x);
        miny = min(miny, a[i].y);
        maxy = max(maxy, a[i].y);
        // xs.insert(a[i].x);
        // ys.insert(a[i].y);
    }
    if (maxy - miny > maxx - minx)
        for (int i = 0; i < n; i++) swap(a[i].x, a[i].y);
    sort(a.begin(), a.end());
    // cout << "done ";
    for (int i = 0; i < n; i++) {
        point left = {a[i].x - sqrt_res, 0};
        auto it    = lower_bound(a.begin(), a.end(), left);
        for (; abs(it->x - a[i].x) <= sqrt_res and it != a.end(); it++) {
            // cout << it->x << " " << it->y << endl;
            if (it->x == a[i].x and it->y == a[i].y or
                abs(it->y - a[i].y) > sqrt_res)
                continue;
            ll xr = it->x - a[i].x;
            ll yr = it->y - a[i].y;
            ull r = xr * xr + yr * yr;
            if (r < res) {
                res      = r;
                sqrt_res = sqrt(r) + 1;
            }
        }
    }
    printf("%lld\n", res);
    // cout << res << endl;
}

