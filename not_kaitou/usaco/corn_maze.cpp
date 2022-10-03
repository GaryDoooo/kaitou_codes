#include <iostream>
using namespace std;
int a[305][205];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
struct door {
    int x1 = -1, y1, x2, y2;
} tp[1005];
long long res[305][305];
int n, m;

long long dfs(int x, int y) {
    // cout << x << " " << y << endl;
    if (res[x][y] > 0 and res[x][y] < 1e8 or res[x][y] > 1e10) return res[x][y];
    if (a[x][y] == 2) return res[x][y] = 1;
    long long ans = 1e18;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 1 or ny < 1) continue;
        if (nx > m or ny > n) continue;
        if (a[nx][ny] == 2)
            return res[x][y] = 1;
        else if (a[nx][ny] == 3)
            ans = min(ans, (long long)1e9);
        else if (a[nx][ny] == 0) {
            // if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
            a[nx][ny] = 3;
            ans       = min(ans, dfs(nx, ny) + 1);
            a[nx][ny] = 0;
            // }
        } else if (a[nx][ny] >= 1000) {
            // if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
            int tn = a[nx][ny] - 1000;
            if (tp[tn].x1 != nx or tp[tn].y1 != ny) {
                nx = tp[tn].x1;
                ny = tp[tn].y1;
            } else {
                nx = tp[tn].x2;
                ny = tp[tn].y2;
            }
            // a[nx][ny] = 1;
            ans       = min(ans, dfs(nx, ny) + 1);
            a[nx][ny] = tn + 1000;
            // }
        }
    }
    return res[x][y] = ans;
}

int main() {
    cin >> n >> m;
    int cx, cy;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            char temp;
            cin >> temp;
            if (temp == '#') {
                a[x][y] = 1;
            }
            if (temp == '.') {
                a[x][y] = 0;
            }
            if (temp == '@') {
                cx = x;
                cy = y;
            }
            if (65 <= temp and temp <= 90) {
                if (tp[(temp - 64)].x1 == -1) {
                    tp[(temp - 64)].x1 = x;
                    tp[(temp - 64)].y1 = y;
                    a[x][y]            = (temp - 64) + 1000;
                } else {
                    tp[(temp - 64)].x2 = x;
                    tp[(temp - 64)].y2 = y;
                    a[x][y]            = (temp - 64) + 1000;
                }
            }
            if (temp == '=') {
                a[x][y] = 2;
            }
            res[x][y] = -1;
        }
    }
    // cout << tp[23].x1 << " " << tp[23].y1 << " " << tp[23].x2 << " " <<
    // tp[23].y2; cout << endl;

    a[cx][cy] = 3;
    cout << dfs(cx, cy) << endl;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (res[x][y] > 1000)
                cout << "# ";
            else
                cout << res[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            cout << a[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

