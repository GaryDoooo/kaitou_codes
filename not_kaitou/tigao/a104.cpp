#include <bits/stdc++.h>
using namespace std;
int f[100005][30], a[100005], n, l, q, s, e, head = 1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &l);
    for (int i = 1; i <= n; i++)
        while (a[head] < a[i] - l) f[head++][0] = i - 1;
    for (; head <= n; head++) f[head][0] = n;
    for (int j = 1, k = 2; k < n; j++, k <<= 1) {
        for (int i = 1; i + k <= n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < 4; j++) cout << f[i][j] << " ";
        cout << endl;
    }
    scanf("%d", &q);
    // cout << q << endl;
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &s, &e);
        // cout << s << " " << e << endl;
        int k   = trunc(log2(e - s));
        int res = 0, t = s;
        while (t < e) {
            if (f[t][k] == n and k > 0) {
                k--;
            } else {
                res += 1 << k;
                t = f[t][k];
            }
        }
        printf("%d\n", res);
    }
}

