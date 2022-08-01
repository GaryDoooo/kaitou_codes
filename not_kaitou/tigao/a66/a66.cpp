#include <bits/stdc++.h>
using namespace std;
int n, t, k, res, v[105], h[105], a[2005];
int main() {
    scanf("%d %d %d", &n, &t, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", v + i, h + i);
        for (int j = 0; (j + h[i]) / 5 * 4 <= t; j += 5)
            a[j + h[i]] = max(a[j + h[i]], a[j] + v[i]);
    }
    res = a[t / 5 * 5];
    for (int i = 0; i < n; i++) {
        if (h[i] < k) continue;
        cout << i << " " << (t - h[i]) / 4 * 5 << " "
             << v[i] + a[(t - h[i]) / 4 * 5] << endl;
        res = max(res, v[i] + a[(t - h[i]) / 4 * 5]);
    }
    cout << res << endl;
}
