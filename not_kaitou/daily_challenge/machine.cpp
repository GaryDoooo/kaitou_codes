#include <bits/stdc++.h>
using namespace std;
int n, m, res = 0, p[10][16], r[10], rr[10];
void dfs(int index, int machine_left, int value) {
    if (machine_left < 0 ) return;
    if (machine_left == 0 or index >= n) {
        if (value > res) {
            res = value;
            for (int i = 0; i < n; i++) rr[i] = r[i];
        }
        return;
    }
    for (int i = 0; i <= machine_left; i++) {
        r[index] = i;
        dfs(index + 1, machine_left - i, value + p[index][i]);
        r[index] = 0;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) cin >> p[i][j];
    }
    dfs(0, m, 0);
    cout << res << endl;
    for (int i = 0; i < n; i++) cout << i + 1 << " " << rr[i] << endl;
}