#include <bits/stdc++.h>
using namespace std;
struct stage {
    int x, y, hp, steps;
};
int main() {
    int h, w;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    cin >> h >> w;
    int a[h][w], sx, sy;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[y][x] == 2) sx = x, sy = y;
        }
    deque<stage> s;
    s.push_back({sx, sy, 6, 0});
    int done[h][w];
    done[sy][sx] = 6;
    memset(done, 0, sizeof(done));
    while (!s.empty()) {
        stage now = s.front();
        s.pop_front();
        if (now.hp <= 1) continue;
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx < 0 or nx >= w or ny < 0 or ny >= h) continue;
            if (a[ny][nx] == 0) continue;
            if (a[ny][nx] == 3) {
                cout << now.steps + 1;
                return 0;
            }
            if (a[ny][nx] == 4) {
                if (6 <= done[ny][nx]) continue;
                done[ny][nx] = 6;
                s.push_back({nx, ny, 6, now.steps + 1});
            } else {
                if (now.hp - 1 <= done[ny][nx]) continue;
                done[ny][nx] = now.hp - 1;
                s.push_back({nx, ny, now.hp - 1, now.steps + 1});
            }
        }
    }
    cout << -1;
}

