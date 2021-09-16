#include <bits/stdc++.h>
using namespace std;
bool *gen_prime_map(int up_limit) {
    bool *prime;
    prime = (bool *) malloc((up_limit + 1) * sizeof(bool));
    memset(prime, 1, (1 + up_limit) * sizeof(bool));
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
    bool *p = gen_prime_map(100000);
    int target[5] = {0}, temp = n;
    for (int i = 0; i < 5; i++) {
        target[i] = temp % 10;
        temp /= 10;
        if (temp == 0) break;
    }
    int res[50000], steps[50000], index = 0;
    for (int i = 0; i < 100000; i++) {
        if (p[i]) {
            int from[5] = {0};
            temp = i;
            for (int j = 0; j < 5; j++) {
                from[j] = temp % 10;
                temp /= 10;
                if (temp == 0) break;
            }
            int step = 0;
            for (int j = 0; j < 5; j++) {
                step += min(min(abs(target[j] - from[j]), abs(target[j] + 10 - from[j])), abs(from[j] + 10 - target[j]));
            }
            res[index] = i;
            steps[index++] = step;
        }
    }
    int max_steps = 100000, res_num;
    for (int i = index - 1; i >= 0; i--) {
        if (steps[i] < max_steps) max_steps = steps[i], res_num = res[i];
    }
    printf("%05d", res_num);
    // cout << max_steps << endl;
}