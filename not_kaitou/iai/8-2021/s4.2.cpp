#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y, dist2mid;
    int operator*(point p) const { return max(abs(p.x - x), abs(p.y - y)); }
};
bool cmp(point &p1, point &p2) { return p1.dist2mid < p2.dist2mid; }
int main() {
    int n;
    cin >> n;
    point p[n];
    long long sum_x = 0, sum_y = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        sum_x += p[i].x;
        sum_y += p[i].y;
    }
    point mid;
    mid.x = sum_x / n;
    mid.y = sum_y / n;
    for (int i = 0; i < n; i++) {
        p[i].dist2mid = p[i] * mid;
    }
    sort(p, p + n, cmp);
    long long res = 1e18;
    for (int i = 0; i < min(n, 10); i++) {
        long long dist = 0;
        for (int j = 0; j < n; j++) dist += p[i] * p[j];
        res = min(res, dist);
    }
    cout << res << endl;
}

