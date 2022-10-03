#include <bits/stdc++.h>
using namespace std;
int n, x, f[1123456], c, d;
int main() {
    scanf("%d%d", &n, &x);
    memset(f, 127, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        for (int j = 0; d = j + c, d <= x; j++) f[d] = min(f[d], f[j] + 1);
    }
    if (f[x] < 1e8)
        cout << f[x] << endl;
    else
        puts("-1");
}
