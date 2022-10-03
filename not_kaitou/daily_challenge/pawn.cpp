#include <bits/stdc++.h>
using namespace std;
int a[21][21], n, m;
int count(int x, int y) {
    if (x > n or y > m) return 0;
    if (x == n and y == m) return 1;
    if (a[x][y]) return 0;
    return count(x + 1, y) + count(x, y + 1);
}
int main() {
    int X, Y;
    cin >> n >> m >> X >> Y;
    memset(a, 0, sizeof(a));
    int dx[] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
    for (int i = 0; i <= 8; i++) {
        int nx = X + dx[i], ny = Y + dy[i];
        if (nx >= 0 and nx <= n and ny >= 0 and ny <= m) a[nx][ny] = 1;
    }
    cout << count(0, 0) << endl;
    return 0;
}