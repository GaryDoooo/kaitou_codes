#include <bits/stdc++.h>
#define W 22
using namespace std;
int h, w, res = 1e9;
int a[500], cnt, b[500], flip[100];
void move(int x) {
    // int dx[] = {0, 0, 0, 1, -1};
    // int dy[] = {0, 1, -1, 0, 0};
    // for (int i = 0; i < 5; i++) {
    // b[y + dy[i]][x + dx[i]] = 1 ^ b[y + dy[i]][x + dx[i]];  //];
    int d[] = {0, -1, 1, W, -W};
    for (int i = 0; i < 5; i++) b[x + d[i]] = 1 ^ b[x + d[i]];
    cnt++;
}
void simulate() {
    memcpy(b, a, sizeof(a));
    cnt = 0;
    for (int x = 1; x <= w; x++) {
        if (flip[x - 1]) move(W + x);
    }
    for (int y = 2 * W; y <= h * W; y += W) {
        for (int x = 1; x <= w; x++) {
            if (b[y - W + x]) move(y + x);
        }
    }
    int s = accumulate(b + W * h + 1, b + W * h + w + 1, 0);
    // for (int x = W*h+1; x <= W*h+w; x++) s += b[h][x];
    if (s == 0) res = min(res, cnt);
}
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (c ^ 48), c = getchar();
    return x;
}
int main() {
    cin >> h >> w;
    for (int y = 1; y <= h; y++)
        for (int x = 1; x <= w; x++) a[y * W + x] = read();
    for (int i = 0; i < (1 << w); i++)
        for (int j = 0; j < w; j++) {
            flip[j] = (i >> j) & 1;
            simulate();
        }
    if (res == 1e9)
        printf("Impossible\n");
    else
        cout << res;
}

