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
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
int main() {
    int a, b;
    cin >> a >> b;
    // write(a); putchar('_'); write(b);
    bool *prime = gen_prime_map(b);
    int max_digits = log(b) / log(10) + 1;
    for (int i = a; i < min(b, 10); i++) {
        if (prime[i]) write(i), putchar('\n');
    }
    for (int digit = 2; digit <= max_digits; digit++) {
        int start = pow(10, (digit - 1) / 2);
        for (int head = start; head < start * 10; head++) {
            string head_str = to_string(head);
            string tail_str(head_str.rbegin(), head_str.rend());
            if (digit & 1) head_str.pop_back();
            head_str += tail_str;
            int number = atoi(head_str.c_str());
            if (number >= a and number <= b)
                if (prime[number]) write(number), putchar('\n');
        }
    }
    // cout << prime[9743479];
    return 0;
}