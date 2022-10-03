#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) { ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;// * f;
}
int main() {
    int t = read(), n = read(), g = read();
    if (t <= 1) { cout << g; return 0;}
    int p[n][t], v[10005];
    for (register int d = 0; d < t; d++)
        for (register int i = 0; i < n; i++) p[i][d] = read();
    for (register int d = 0; d < t - 1; d++) {
        v[0] = 0;
        for (register int m = 1; m <= g; m++) {
            v[m] = v[m - 1] + 1;
            for (register int i = 0; i < n; i++) {
                if (p[i][d] >= p[i][d + 1] or m < p[i][d]) continue;
                v[m] = max(v[m], v[m - p[i][d]] + p[i][d + 1]);
            }
        }
        g = v[g];
    }
    cout << g;
    return 0;
}