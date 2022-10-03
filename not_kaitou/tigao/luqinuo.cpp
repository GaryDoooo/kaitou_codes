#include <bits/stdc++.h>
using namespace std;
int a[212345], f[212345], q[212345], head = 1, tail, n, l, r, res = -2e9;
int main() {
    scanf("%d%d%d", &n, &l, &r);
    memset(f, 128, sizeof(f));
    f[0] = 0;
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i - l < 0) continue;
        while (head <= tail and q[head] < i - r) head++;
        while (head <= tail and f[i - l] > f[q[tail]]) tail--;
        q[++tail] = i - l;
        f[i]      = a[i] + f[q[head]];
    }
    for (int i = n - r + 1; i <= n; i++) res = max(res, f[i]);
    cout << res;
}
