#include <iostream>
#include <cstring>
using namespace std;
long long a[305][305], f[305][305], sum[305][305];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum[j][i] = sum[j][i - 1] + a[i][j];
        }
    }
    memset(f, 127, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        f[1][i] = f[1][i - 1] + a[i][1];
    }
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int x = 2; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            for (int s = 1; s <= n; s++) { // y to s
                if (s < y) { // s above y
                    f[x][s] = min(f[x - 1][y] + sum[x][y] - sum[x][s - 1], f[x][s]);
                } else if (s == y) {
                    f[x][s] = min(f[x][s], f[x - 1][y] + a[y][x]);
                } else { // s below y
                    f[x][s] = min(f[x][s], f[x - 1][y] + sum[x][s] - sum[x][y - 1]);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << f[m][n];
    return 0;
}