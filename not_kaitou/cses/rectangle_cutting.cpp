#include <cstring>
#include <iostream>
using namespace std;
int f[5005][5005];
int cut(int h, int w) {
    if (h == w) return 0;
    if (h > w) swap(h, w);
    if (f[h][w] >= 0) return f[h][w];
    int res = 1e9;
    for (int x = 1; x <= w >> 1; x++)
        res = min(res, 1 + cut(h, x) + cut(h, w - x));
    for (int y = 1; y <= h >> 1; y++)
        res = min(res, 1 + cut(y, w) + cut(h - y, w));
    return f[h][w] = res;
}

int main() {
    int h, w;
    memset(f, 128, sizeof(f));
    cin >> h >> w;
    cout << cut(h, w) << endl;
}

