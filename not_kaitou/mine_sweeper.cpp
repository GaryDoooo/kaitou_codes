#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("mine_sweeper.in", "r", stdin);
    int w, h, a[102][102] = {0};
    cin >>  h >> w;
    // int a[w + 2][h + 2];
    // memset(a, 0, (w + 2) * (h + 2)*sizeof(int));
    for (int y = 1; y <= h; y ++)
        for (int x = 1; x <= w; x++) {
            char c;
            cin >> c;
            if (c == '*') a[x][y] = 1;
        }
    for (int y = 1; y <= h; y ++) {
        for (int x = 1; x <= w; x++) {
            if (a[x][y] == 1) {
                cout << '*';
                continue;
            }
            cout << a[x + 1][y] + a[x - 1][y] + a[x][y - 1] + a[x][y + 1] + a[x - 1][y - 1] + a[x + 1][y + 1] + a[x - 1][y + 1] +
                 a[x + 1][y - 1];
        }
        cout << endl;
    }
    return 0;
}