#include <bits/stdc++.h>
using namespace std;
struct cheese {
    int h, v;
};
bool operator<(cheese const& aa, cheese const& b) { return aa.h < b.h; }
cheese c[105];
int n, t, k, res, j, normal[2005], compressed[2005];
// map<int, int> a[2005];
int main() {
    scanf("%d %d %d", &n, &t, &k);
    for (int i = 0; i < n; i++) scanf("%d %d", &c[i].v, &c[i].h);
    sort(c, c + n);
    memset(normal, 128, sizeof(normal));
    memset(compressed, 128, sizeof(compressed));
    normal[0] = 0;
    for (j = 0; j < n and c[j].h < k; j++) {
        for (int i = 0; i + c[j].h <= t; i += 5)
            res = max(res, normal[i + c[j].h] =
                               max(normal[i + c[j].h], normal[i] + c[j].v));
    }
    int shortest_big_cheese = c[j].h;
    for (; j < n; j++) {
        for (int i = 0; i / 5 * 4 + c[j].h <= t; i += 5) {
            res = max(res,
                      compressed[i / 5 * 4 + c[j].h] = max(
                          compressed[i / 5 * 4 + c[j].h], normal[i] + c[j].v));
        }
        for (int i = 5; i + shortest_big_cheese <= t; i++) {
            res = max(res, compressed[i + c[j].h / 5 * 4] =
                               max(compressed[i + c[j].h / 5 * 4],
                                   compressed[i] + c[j].v));
            // for (auto option : a[i]) {
            //     int shortest_big_cheese =
            //         (option.first > 0 ? min(option.first, c[j].h) : c[j].h);
            //     int value       = option.second;
            //     int new_total_h = i + c[j].h;
            //     int new_total_v = value + c[j].v;
            //     if ((new_total_h - shortest_big_cheese) / 5 * 4 +
            //             shortest_big_cheese >
            //         t)
            //         continue;
            //     top = max(top, new_total_h);
            //     res = max(
            //         res, a[new_total_h][shortest_big_cheese] = max(
            //                  a[new_total_h][shortest_big_cheese],
            //                  new_total_v));
            // }
        }
    }
    cout << res;
}

