#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    __int128 s, m, l;
    __int128 res = 0;
    // for (s = 1; s <= n / 3; s++) {
    //     long long cnt = 0;
    //     if ((n - s) % 2 == 0) {
    //         l = m = (n - s) / 2;
    //         cnt++;
    //     } else {
    //         l = (n - s + 1) / 2;
    //         m = (n - s - 1) / 2;
    //     }
    //     if ((m - s) * 2 < s) {
    //         res += m - s + 1;
    //     } else {
    //         res += s / 2 + (cnt == 1 and s & 1 == 1);
    //     }
    //     // while (l- m < s and m >= s) {
    //     //     res++;
    //     //     l += 1;
    //     //     m -= 1;
    //     // }
    // }
    
    __int128 N = (n - 1) / 4, a1 = 0;
    __int128 an = N / 2;
    res += (a1 + an) * N / 2;
    N  = n / 3 - N + 1;
    s  = (n - 1) / 4 + 1;
    a1 = (n - s) / 2 - s + 1;
    s  = n / 3;
    an = (n - s) / 2 - s + 1;
    res += (a1 + an) * N / 2;
    if (n & 1LL) {
        res += N / 2 + 1;
    }
    cout << res << endl;
}
