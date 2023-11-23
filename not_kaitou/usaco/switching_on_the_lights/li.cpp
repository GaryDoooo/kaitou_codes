#include <bits/stdc++.h>
using namespace std;
struct libby {
    int x, y;
};
int n, a[105][105], m, x, y, x2, y2;
vector<libby> e[105][105];
int vis[105][105], can_vis[105][105];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
    int res       = 1;
    vis[x][y]     = 1;
    can_vis[x][y] = 1;
    for (auto to : e[x][y])
        if (can_vis[to.x][to.y] and a[to.x][to.y] == 0) {
            a[to.x][to.y] = 1;
            res += dfs(to.x, to.y);
        } else {
            a[to.x][to.y] = 1;
        }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 or nx > n or ny <= 0 or ny > n) continue;
        can_vis[nx][ny] = 1;
        if (vis[nx][ny] or a[nx][ny] == 0) continue;
        res += dfs(nx, ny);
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d %d", &x, &y, &x2, &y2);
        e[x][y].push_back({x2, y2});
    }
    a[1][1] = 1;
    int ans = 0;
    dfs(1, 1);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++) ans += a[x][y];
    cout << ans << endl;
}
