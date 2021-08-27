#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1}, dy[] = { -1, 1, 0, 0};
static int a[3000][3000] , total_cows = 0;
void add_cow(int x, int y);
void look_around(int x, int y, bool root) {
    int missing_x, missing_y, nx, ny, total = 0;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i]; ny = y + dy[i];
        if (a[nx][ny] == 0) {
            missing_x = nx; missing_y = ny;
        } else {
            total++;
            if (root) look_around(nx, ny, false);
        }
    }
    if (total == 3) add_cow(missing_x, missing_y);
}
void add_cow(int x, int y) {
    total_cows += (a[x][y] == 0);
    a[x][y] = 1;
    look_around(x, y, true);
}
int main() {
    memset(a, 0, sizeof(a));
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        x += 1000; y += 1000;
        add_cow(x, y);
        cout << total_cows - i << endl;
    }
    return 0;
}