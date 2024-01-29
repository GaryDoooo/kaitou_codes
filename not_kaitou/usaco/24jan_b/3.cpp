#include <bits/stdc++.h>
using namespace std;
long long n, res;
long long a_in[112345];
__int128 a[112345];

int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a_in[i]);
    for (int i = 1; i <= n; i++) a[i] = a_in[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0)
            res += a[i];
        else
            res -= a[i];
        for (int j = 1; j + i <= n; j++) {
            a[j + i] += -(j + 1) * a[i];
        }
    }
    cout << res << endl;
}

