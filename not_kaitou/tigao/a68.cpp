#include <bits/stdc++.h>
using namespace std;
int n, m, a[210005], b[2105], s, e;
int main() {
    scanf("%d", &n);
    memset(b, 128, sizeof(b));
    memset(a, 128, sizeof(a));
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        b[i / 100] = max(b[i / 100], a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        s--;
        e--;
        int res = -2e9;
        if (s / 100 == e / 100)
            for (int j = s; j <= e; j++) res = max(res, a[j]);
        else {
            for (int j = s / 100 + 1; j < e / 100; j++) res = max(res, b[j]);
            for (int j = s; j < min((s / 100 + 1) * 100, e + 1); j++)
                res = max(res, a[j]);
            for (int j = max(s, (e / 100) * 100); j <= e; j++)
                res = max(res, a[j]);
        }
        printf("%d\n", res);
    }
}

