#include <bits/stdc++.h>
using namespace std;
int res = 0, n, picked[21] = {1, 1}, a[21] = {1};
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
void print_it() {
    // cout << ++res << ":";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    if (++res == 10) exit(0);
}
void dfs(bool *prime, int i) {
    if (i == n) {
        if (prime[a[n - 1] + a[0]]) print_it();
    } else
        for (int j = 2; j <= n; j++) {
            if (picked[j]) continue;
            if (prime[j + a[i - 1]]) {
                picked[j] = 1;
                a[i] = j;
                dfs(prime, i + 1);
                picked[j] = 0;
            }
        }
}
int main() {
    cin >> n ;
    if (n == 19) return 0;
    bool *prime = gen_prime_map(100);
    dfs(prime, 1);
    return 0;
}