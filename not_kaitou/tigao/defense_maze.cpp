#include <bits/stdc++.h>
using namespace std;
int w, h;
int a[1005][1005];
inline int read() {
    int x   = 0;  //   , f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        ch = getchar();
    }
    while (isdigit(ch)) {
        x  = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;  // * f;
}
bool connect(int allowed_max) {
    vector<int> qx(w * h), qy(w * h);
    int did[w][h];
    int left = 0, right = 0;
    qx[0] = 0;
    qy[0] = 0;
    memset(did, 0, sizeof(did));
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    did[0][0] = 1;
    while (left <= right) {
        int x = qx[left], y = qy[left++];
        // cout << x << " " << y << endl;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx < 0 or ny < 0 or nx >= w or ny >= h) continue;
            if (nx == w - 1) return true;
            if (a[nx][ny] <= allowed_max and did[nx][ny] == 0) {
                qx[++right] = nx;
                qy[right]   = ny;
                did[nx][ny] = 1;
            }
        }
    }
    return false;
}

int main() {
    w = read(), h = read();
    memset(a, 0, sizeof(a));
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++) a[x][y] = read();
    int left = 0, right = 1000;
    while (left < right) {
        int mid = (left + right) / 2;
        // cout << mid << " " << connect(mid) << endl;
        if (connect(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

