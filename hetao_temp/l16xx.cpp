#include <iostream>
using namespace std;`1
int main() {
    int a[100005], n, mod = 10007, asum = 0, isum, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        asum += a[i];
    }
    isum = (n + 1) * n / 2;
    for (int i = 1; i <= n; i++) {
        ans = (ans + i * (isum - i) + a[i] * (asum - a[i])) % mod;
        ans = (ans + ((i * a[i]) % mod * ((n - 1) % mod)) % mod * 2) % mod;
    }
    for (int i = 1; i <= mod - 2; i++) {
        ans = (ans * 2) % mod;
    }
    cout << ans;
}

