#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x  = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
struct point {
    int x, y, i;
    int operator*(point p) const { return max(abs(p.x - x), abs(p.y - y)); }
    bool operator<(point p) const { return x < p.x; }
    bool operator>(point p) const { return y < p.y; }
};
bool working(int d, point *res, point p[], point px[], point py[], int n) {
    // cout << "d=" << d << endl;
    int picked[n] = {0};
    for (int i = 0; i < n; i++) {
        if (px[i].x <= px[0].x + d and px[i].x + d >= px[n - 1].x)
            picked[px[i].i] = 1;
        if (py[i].y <= py[0].y + d and py[i].y + d >= py[n - 1].y)
            picked[py[i].i] = 1;
    }
    // for (int i = 0; i < n; i++) cout << picked[i] << " ";
    // cout << endl;
    res->x = -2e9;
    for (int i = 0; i < n; i++) {
        if (picked[i]) {
            res->x = p[i].x;
            res->y = p[i].y;
            for (int j = 0; j < n; j++)
                if (p[i] * p[j] > d) return false;
        }
    }
    if (res->x == -2e9) return false;
    return true;
}

int main() {
    int n = read();
    point p[n], px[n], py[n];
    for (int i = 0; i < n; i++) p[i].x = read(), p[i].y = read(), p[i].i = i;
    memcpy(px, p, n * sizeof(point));
    memcpy(py, p, n * sizeof(point));
    sort(px, px + n);
    sort(py, py + n, greater<point>());
    // for (int i = 0; i < n; i++) cout << px[i].x << "," << px[i].y << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << py[i].x << "," << py[i].y << " ";
    // cout << endl;
    int left = 0, right = max(px[n - 1].x - px[0].x, py[n - 1].y - py[0].y);
    point res;
    while (left < right) {
        int mid = (left + right) / 2;
        if (working(mid, &res, p, px, py, n)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    working(left, &res, p, px, py, n);
    // cout << res.x << " " << res.y << "@" << left << endl;
    long long dist = 0;
    for (int i = 0; i < n; i++) {
        dist += p[i] * res;
    }
    cout << dist;
}

