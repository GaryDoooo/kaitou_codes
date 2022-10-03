#include <bits/stdc++.h>
using namespace std;
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
    int n;
    cin >> n;
    bool *prime = gen_prime_map(n);
    for (int i = 0; i < n; i++)
        if (prime[i]) cout << i << ",";
}