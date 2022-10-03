#include <bits/stdc++.h>
using namespace std;
void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x == 0)return;
    write(x / 10);
    putchar('0' + x % 10);
}
bool not_prime[5000005] = {1, 1, 0, 0};
int small_prime[3] = {3, 5, 7};
int n, sum, temp;
void add_prime(int p) {
    int step = 2 * p;
    for (int i = 3 * p; i <= n; i += step) not_prime[i] = true;
}
void print(int i) {
    write(i);
    putchar('\n');
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    bool is_prime;
    int limit = (int)sqrt(n);
    print(2);
    for (int i = 0; i < 3; i++) if (small_prime[i] <= n)add_prime(small_prime[i]), print(small_prime[i]);
    for (int i = 11; i <= n; i += 2) {
        if (not_prime[i]) continue;
        if (i < limit)
            add_prime(i);
        sum = 0;
        temp = i;
        while (temp > 0) sum += temp % 10, temp /= 10;
        if (not_prime[sum] or sum % 2 == 0 and sum > 2 )continue;
        print(i);
    }
    return 0;
}