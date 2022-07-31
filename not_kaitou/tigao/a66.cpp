#include <bits/stdc++.h>
using namespace std;
struct cheese {
    int h, v;
};
bool operator<(cheese const& aa, cheese const& b) { return aa.h < b.h; }
cheese c[105];
int n, t, k, res, top, j;
map<int, int> a[2005];
int main() {
    scanf("%d %d %d", &n, &t, &k);
    for (int i = 0; i < n; i++) scanf("%d %d", &c[i].v, &c[i].h);
    sort(c, c + n);
    // for (int i = 0; i < n; i++) cout << c[i].h << " " << c[i].v << endl;
    a[0][0] = 0;
    for (j = 0; j < n; j++) {
        if (c[j].h >= k) break;
        // for (int i = top; i >= 0; i--) {
        for (int i = 0; i < t; i++)
            res = max(res, a[i + c[j].h][0] =
                               max(a[i + c[j].h][0], a[i][0] + c[j].v));
        // top += c[j].h;
    }
    for (; j < n; j++) {
        // for (int i = top; i >= 0; i--) {
        for (int i = 0; i < t * 2; i++) {
            for (auto option : a[i]) {
                int shortest_big_cheese =
                    (option.first > 0 ? min(option.first, c[j].h) : c[j].h);
                int value       = option.second;
                int new_total_h = i + c[j].h;
                int new_total_v = value + c[j].v;
                if ((new_total_h - shortest_big_cheese) / 5 * 4 +
                        shortest_big_cheese >
                    t)
                    continue;
                top = max(top, new_total_h);
                res = max(
                    res, a[new_total_h][shortest_big_cheese] = max(
                             a[new_total_h][shortest_big_cheese], new_total_v));
            }
        }
    }
    cout << res;
}

