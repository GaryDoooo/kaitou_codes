#include <bits/stdc++.h>
using namespace std;
int main() {
    int w, h;
    cin >> w >> h;
    int m[h + 1][w + 1], qx[w * h], qy[w * h];
    int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
    // int sx, sy;
    memset(m, 0, sizeof(m));
    for (int y = 0; y < h; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < w; x++) {
            if (s[x] == '*')
                m[y][x] = 1;
            else if (s[x] == 'K') {
                qx[0]   = x;
                qy[0]   = y;
                m[y][x] = 1;
            } else if (s[x] == 'H') {
                m[y][x] = 1e9;
            }
        }
    }
    // memset(done, 0, sizeof(done));
    int left = 0, right = 1;
    while (left < right) {
        int x = qx[left], y = qy[left++];
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or nx >= w or ny < 0 or ny >= h) continue;
            if (m[ny][nx] == 1e9) {
                cout << m[y][x];
                return 0;
            }
            if (m[ny][nx] == 0) {
                m[ny][nx]   = m[y][x] + 1;
                qx[right]   = nx;
                qy[right++] = ny;
            }
        }
    }
}

