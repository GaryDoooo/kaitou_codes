#include <bits/stdc++.h>
using namespace std;
bool counted_s[101][101], counted_r[101][101];
int square(int x, int y) {
    if (x < 1 or y < 1) return 0;
    if (counted_s[x][y]) return 0;
    counted_s[x][y] = 1;
    return	square(x - 1, y) + square(x, y - 1) + min(x, y);
}
int rectangle(int x, int y) {
    if (x < 1 or y < 1) return 0;
    if (counted_r[x][y]) return 0;
    counted_r[x][y] = 1;
    return	rectangle(x - 1, y) + rectangle(x, y - 1) + x * y - min(x, y);
}
int main() {
    int x, y;
    cin >> x >> y;
    memset(counted_s, 0, sizeof(counted_s));
    memset(counted_r, 0, sizeof(counted_r));
    cout << square(x, y) << " " << rectangle(x, y);
    return 0;
}