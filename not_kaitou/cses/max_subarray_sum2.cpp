#include <bits/stdc++.h>
using namespace std;
long long s[212345], res = -2e18;
int n, a, b, x, q[212345], head = 1, tail;
int main() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        s[i] = s[i - 1] + x;
    }
    for (int i = a; i <= n; i++) {
        while (head <= tail and q[head] < i - b) head++;
        while (head <= tail and s[q[tail]] > s[i - a]) tail--;
        q[++tail] = i - a;
        res       = max(res, s[i] - s[q[head]]);
    }
    cout << res << endl;
}
