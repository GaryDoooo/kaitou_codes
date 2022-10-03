#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int h = read(), w = read();
    long long max_last_col[h], max_this_col_from_top[h], max_this_col_from_btm[h];
    int a[h][w];
    for (register int i = 0; i < h; i++)
        for (register int j = 0; j < w; j++) a[i][j] = read();
    for (register int x = 0; x < w; x++) {
        if (x == 0) {
            max_last_col[0] = a[0][0];
            for (register int y = 1; y < h; y++)
                max_last_col[y] = a[y][0] + max_last_col[y - 1];
        } else if (x == w - 1) {
            max_this_col_from_top[0] = max_last_col[0] + a[0][x];
            for (register int y = 1; y < h; y++) {
                max_this_col_from_top[y] = max(
                                               max_last_col[y],
                                               max_this_col_from_top[y - 1]
                                           ) + a[y][x];
            }
        } else {
            max_this_col_from_top[0] = max_last_col[0] + a[0][x];
            for (register int y = 1; y < h; y++) {
                max_this_col_from_top[y] = max(
                                               max_last_col[y],
                                               max_this_col_from_top[y - 1]
                                           ) + a[y][x];
            }
            max_this_col_from_btm[h - 1] = max_last_col[h - 1] + a[h - 1][x];
            for (register int y = h - 2; y >= 0; y--) {
                max_this_col_from_btm[y] = max(
                                               max_this_col_from_btm[y + 1],
                                               max_last_col[y]
                                           ) + a[y][x];
            }
            for (register int y = 0; y < h; y++)
                max_last_col[y] = max(max_this_col_from_btm[y], max_this_col_from_top[y]);
        }
    }
    cout << max_this_col_from_top[h - 1];
    return 0;
}