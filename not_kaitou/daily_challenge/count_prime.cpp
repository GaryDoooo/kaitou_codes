#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> not_prime(n + 1, 0);
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= n; j += 2 * i) not_prime[j] = 1;
    }
    cout << (n + 1) / 2 - accumulate(not_prime.begin(), not_prime.end(), 0) << endl;
}
