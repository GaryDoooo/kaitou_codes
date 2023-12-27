#include <bits/stdc++.h>
using namespace std;
char inp[1005];
int m[1005][1005], w, h, res;

void dfs(int x, int y) {
    m[x][y]   = 0;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (m[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    cin >> h >> w;
    for (int y = 1; y <= h; y++) {
        scanf("%s\n", inp);
        for (int x = 0; x < w; x++) m[x + 1][y] = inp[x] == '.';
    }
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            if (m[x][y]) {
                res++;
                dfs(x, y);
            }
        }
    }
    cout << res << endl;
}
