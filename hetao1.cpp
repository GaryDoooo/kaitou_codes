#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int mp[305][305];
struct point {
    int x, y, num;
};
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int bfs() {
    queue<point> q;
    q.push((point) {0, 0, 0});
    mp[0][0] = 0;
    while (!q.empty()) {
        point now = q.front();
        q.pop();
        // cout << now.x << " " << now.y << endl;
        for (int i = 1; i <= 4; i++) {
            for (int m = 1; m <= 2; m++) {
                int nx = now.x + dx[i] * m, ny = now.y + dy[i] * m;
                if (mp[nx][ny] > 600) {
                    return now.num + 1;
                }
                if (nx > 300 or ny > 300 or nx < 0 or ny < 0)
                    continue;
                if (mp[nx][ny] <= now.num + 1) {
                    continue;
                }
                q.push((point) {nx, ny, now.num + 1});
                mp[nx][ny] = now.num + 1;
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    memset(mp, 127, sizeof(mp));
    for (int i = 1; i <= n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        mp[x][y] = t;
        for (int d = 1; d <= 4; d++) {
            if (x + dx[d] > 300 or x + dx[d] < 0 or y + dy[d] > 300 or y + dy[d] < 0)
                continue;
            mp[x + dx[d]][y + dy[d]] = min(mp[x + dx[d]][y + dy[d]], t);
        }
    }
    cout << bfs();
    return 0;
}
