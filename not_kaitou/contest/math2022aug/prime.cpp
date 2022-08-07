#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ull m, n = 1e6;
    bool p[1000005];
    memset(p, 1, sizeof(p));
    p[1] = 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) p[j] = 0;
        }
    }
    int primes[1000005], prime_count = 1;
    primes[0] = 2;
    for (int i = 3; i <= n; i += 2)
        if (p[i]) primes[prime_count++] = i;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        ull res = 0, p_cubic;
        for (int j = 0; j < prime_count; j++) {
            p_cubic = primes[j];
            p_cubic = p_cubic * p_cubic * p_cubic;
            if (m < p_cubic) break;
            while (m % p_cubic == 0) {
                res++;
                m /= p_cubic;
            }
        }
        cout << res << endl;
    }
}
