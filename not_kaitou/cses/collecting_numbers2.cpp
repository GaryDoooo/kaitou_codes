#include <bits/stdc++.h>
using namespace std;
int a[212345], p[212345], res, n, t, c, d;
int count(int j) {
    // int j = a[i];
    if (p[j - 1] < p[j] and p[j] < p[j + 1]) return 1;
    if (p[j - 1] > p[j] and p[j] > p[j + 1]) return 3;
    return 2;
}
int cnt(int c, int d) {
    int x = a[c], y = a[d];
    if (abs(x - y) > 1) return count(x) + count(y);
    if (x < y) swap(x, y);
    return count(x) + count(y) - (p[x] < p[y]);
}
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (p[a[i] - 1] == 0) res++;
        p[a[i]] = i;
    }
    while (t--) {
        scanf("%d%d\n", &c, &d);
        int prev = cnt(c, d);  // count(c) + count(d);
        swap(a[c], a[d]);
        swap(p[a[c]], p[a[d]]);
        res = res - prev + cnt(c, d);  // count(c) + count(d);
        printf("%d\n", res);
    }
}
