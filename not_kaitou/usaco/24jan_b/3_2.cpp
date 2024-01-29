#include <bits/stdc++.h>
using namespace std;
int n;
long long res;
long long accumulator;  // accumulation of previous positions
// long long a[112345];    // init bacteria
long long b[212345];  // change val of the position
long long c[212345];  // pref sum of b(0) to b(i-1)
int main() {
    scanf("%d", &n);
    // for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);
        b[i] = a + accumulator;
        b[i] = -b[i];
        c[i] = c[i - 1] + b[i - 1];
        accumulator += c[i] + 2 * b[i];
    }
    for (int i = 1; i <= n; i++) res += abs(b[i]);
    printf("%lld\n", res);
}

