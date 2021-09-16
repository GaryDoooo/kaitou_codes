#include <bits/stdc++.h>
using namespace std;
long long n;
__int128 brute_force(long long from, long long to) {
    __int128 res = 0;
    long long m;
    for (long long s = from; s <= to; s++) {
        long long cnt = 0;
        if ((n - s) % 2 == 0) {
            m = (n - s) / 2;
            cnt++;
        } else {
            m = (n - s - 1) / 2;
        }
        if ((m - s) * 2 < s) {
            res += m - s + 1;
        } else {
            res += s / 2 + (cnt == 1 and s & 1 == 1);
        }
    }
    return res;
}
__int128 sum_half(__int128 N) {
    __int128 res = 0;
    if (N & 1) {
        res += (N / 2 + 1) * (N / 2);
    } else {
        res += (N / 2 + 1) * (N / 2) - N / 2;
    }
    return res;
}
std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

int main() {
    cin >> n;
    __int128 res = 0;
    res += sum_half(n / 4 - 9);
    if (n & 1) {
        res += n / 8 - 4;
    }
    res += brute_force(n / 4 - 8, n / 4 + 8);
    res += (n / 3 - (n / 4 + 9) + 1);
    res -= (__int128)(n / 3 + (n / 4 + 9)) *
           (__int128)(n / 3 - (n / 4 + 9) + 1) / 2;
    long long N1 = (n - n / 3), N2 = (n - n / 4 - 9);
    res += sum_half(N2) - sum_half(N1 - 1);
    // print_u128_u(res);
    cout << res;
}
