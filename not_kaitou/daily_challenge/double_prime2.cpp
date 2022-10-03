#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool not_prime[5000005] = {0};
    int n, sum, temp, step;
    cin >> n;
    bool is_prime;
    int limit = (int)sqrt(n);
    cout << 2 << "\n";
    for (int i = 3; i <= n; i += 2) {
        if (not_prime[i]) continue;
        if (i <= limit) {
            step = 2 * i;
            for (int ii = i * i; ii <= n; ii += step) not_prime[ii] = true;
        }
        sum = 0;
        temp = i;
        while (temp > 0) sum += temp % 10, temp /= 10;
        if (not_prime[sum] or sum % 2 == 0 and sum > 2 )continue;
        cout << i << "\n";
    }
    return 0;
}