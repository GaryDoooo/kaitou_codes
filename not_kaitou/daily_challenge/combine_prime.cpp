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
    int a[n], res = 0, max_iter = 1 << n;
    for (int i = 0; i < n; i++) a[i] = read();
    int max_sum = accumulate(a, a + n, 0);
    vector<int> not_prime(max_sum + 1, 0);
    for (int i = 3; i <= sqrt(max_sum); i += 2) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= max_sum; j += 2 * i) not_prime[j] = 1;
    }
    not_prime[0] = 1; not_prime[1] = 1;
    for (int i = 4; i <= max_sum; i += 2) not_prime[i] = 1;
    for (int i = 0; i < max_iter; i++) {
        int sum = 0, ii = i, index = 0;
        while (ii > 0) {
            sum += a[index++] * (ii % 2);
            ii = ii >> 1;
        }
        res += (not_prime[sum] == 0);
    }
    cout << res;
    return 0;
}