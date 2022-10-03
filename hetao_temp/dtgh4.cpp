#include <iostream>
using namespace std;
int n, m, f[165][55][55][55], cnt1, cnt2, cnt3, a[165];

int collect(int pos, int c1, int c2, int c3) {
    if (c1 + c2 + c3 == 0) return 0;
    if (pos == n) return 0;
    if (f[pos][c1][c2][c3]) return f[pos][c1][c2][c3];
    int res = -1;
    if (c1 > 0) {
        res = max(res, collect(pos + 1, c1 - 1, c2, c3) + a[pos + 1]);
    }
    if (c2 > 0) {
        res = max(res, collect(pos + 2, c1, c2 - 1, c3) + a[pos + 2]);
    }
    if (c3 > 0) {
        res = max(res, collect(pos + 3, c1, c2, c3 - 1) + a[pos + 3]);
    }
    return f[pos][c1][c2][c3] = res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int temp;
    for (int i = 1; i <= m; i++) {
        cin >> temp;
        if (temp == 1) cnt1++;
        if (temp == 2) cnt2++;
        if (temp == 3) cnt3++;
    }
    cout << collect(1, cnt1, cnt2, cnt3) + a[1];
    return 0;
}