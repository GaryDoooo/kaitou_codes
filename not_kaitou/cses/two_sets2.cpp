#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, MOD = 1e9 + 7, x, tail;
unsigned int f[250000];
int qw(long long base, int exp) {
    long long res = 1;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
    }
    return res;
}

int main() {
    cin >> n;
    x = n * (n + 1) >> 1;
    if (x & 1) {
        puts("0");
        return 0;
    }
    x    = x >> 1;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = tail; j >= 0; j--) {
            f[j + i] = (f[j + i] + f[j]) % MOD;
        }
        tail = max(x, tail + i);
    }
    // cout << f[x] << endl;
    cout << ((ll)f[x] * (ll)qw(2, MOD - 2)) % MOD << endl;
}
