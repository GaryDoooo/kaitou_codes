#include <bits/stdc++.h>
using namespace std;
int n, a[10] = {0}, picked[10] = {0};
int dfs(int sum, int k, bool *prime) {
    if (k > n) return 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (picked[i]) continue;
        picked[i] = 1;
        res += prime[sum + k * a[i]];
        res += dfs(sum + k * a[i], k + 1, prime);
        picked[i] = 0;
    }
    return res;
}
bool *gen_prime_map(int up_limit) {
    bool *prime;
    prime = (bool *) malloc((up_limit + 1) * sizeof(bool));
    memset(prime, 1, up_limit * sizeof(bool));
    for (int i = 3; i <= sqrt(up_limit); i += 2 ) {
        if (prime[i])
            for (int j = i * i; j <= up_limit; j += 2 * i) prime[j] = 0;
    }
    prime[0] = prime[1] = 0;
    for (int i = 4; i <= up_limit; i += 2) prime[i] = 0;
    return prime;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int max_sum = n * accumulate(a, a + n + 1, 0);
    bool *prime = gen_prime_map(max_sum);
    cout << dfs(0, 1, prime);
    return 0;
}