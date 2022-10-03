#include <bits/stdc++.h>
using namespace std;
long long n;
__int128 brute_force(__int128 from, __int128 to) {
    __int128 res = 0, m;
    for (__int128 s = from; s <= to; s++) {
        __int128 cnt = 0;
        if ((n - s) % 2 == 0) {
            m = (n - s) / 2;
            cnt++;
        } else {
            m = (n - s - 1) / 2;
        }
        if ((m - s) * 2 < s) {
            res += m - s + 1;
        } else {
            res += s / 2 + (cnt == 1 and (s & 1) == 1);
        }
    }
    return res;
}
__int128 sum_half(long long N) {
    __int128 res = 0;
    if (N & 1) {
        res += (N / 2 + 1) * (N / 2);
    } else {
        res += (N / 2 + 1) * (N / 2) - N / 2;
    }
    return res;
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
    res -= (n / 3 + (n / 4 + 9)) * (n / 3 - (n / 4 + 9) + 1) / 2;
    long long N1 = (n - n / 3), N2 = (n - n / 4 - 9);
    res += sum_half(N2) - sum_half(N1 - 1);
    printf("%llx\n", (long long)res);
}
