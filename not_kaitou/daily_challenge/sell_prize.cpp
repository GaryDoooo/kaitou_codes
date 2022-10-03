#include <bits/stdc++.h>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    char ch = nc(); int x = 0; // int flag = 1;
    while (!(ch >= '0' && ch <= '9')) ch = nc();
    while (ch >= '0' && ch <= '9')x = (x << 1) + (x << 3) + (ch ^ 48), ch = nc();
    return x;
}
int main() {
    int n = read();
    int a[n + 1][n + 1];
    memset(a, 0, sizeof(a));
    for (register int y = 1; y <= n; y++) for (register int x = 1; x <= n; x++)
            a[x][y] = a[x][y - 1] + a[x - 1][y] - a[x - 1][y - 1] + read();
    int k = read();
    register int m = read(), res = 0;
    for (register int y = m ; y <= n; y++) {
        for (register int x = m ; x <= n; x++) {
            res = max(res, a[x][y] - a[x - m][y] - a[x][y - m] + a[x - m][y - m]);
        }
    }
    cout << (k > res ? "NO" : "YES") << endl;
}