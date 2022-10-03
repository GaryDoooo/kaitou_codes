#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int f[205][26 * 205];
int a2[205], a5[205], n, K;
ll a;
int get_(ll x, int y) {
    int res = 0;
    while (x % y == 0) {
        res++;
        x /= y;
    }
    return res;
}
int main() {
    cin >> n >> K;
    for (int i = 0; i < n; i++) {
        cin >> a;
        // cout << a << "_";
        a2[i] = get_(a, 2);
        a5[i] = get_(a, 5);
    }
    int total5 = 0;
    memset(f, 128, sizeof(f));
    f[0][0] = 0;
    // for (int i=0;i<n;i++) total5+=a5[i];
    for (int i = 0; i < n; i++) {
        total5 += a5[i];
        for (int j = i + 1; j > 0; j--) {
            for (int k = total5; k >= a5[i]; k--) {
                f[j][k] = max(f[j][k], f[j - 1][k - a5[i]] + a2[i]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, min(f[K][i], i));
    // cout << res << endl;
}

