#include <bits/stdc++.h>
using namespace std;
int res = 0, n;
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
void dfs(vector<int> &primes, int i, int sum, int count) {
    if (i >= primes.size()) return;
    if (sum + primes[i] == n) {
        res = max(res, count + 1);
    } else if (sum + primes[i] < n) {
        dfs(primes, i + 1, sum + primes[i], count + 1);
        dfs(primes, i + 1, sum, count);
    }
}
int main() {
    cin >> n ;
    bool *prime = gen_prime_map(n);
    vector<int> primes{2};
    for (int i = 3; i <= n; i += 2) if (prime[i]) primes.push_back(i);
    // for (int i : primes) {cout << i << " ";}
    dfs(primes, 0, 0, 0);
    cout << res << endl;
    return 0;
}