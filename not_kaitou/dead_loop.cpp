#include <iostream>
#include <cmath>
typedef __int128 L;
using namespace std;

L solve(L a, L b, L c, L maximum) {
    // cout << "a=" << a << "b=" << b << "c=" << c << "maximum=" << maximum << endl;
    if (c == 0) return -1;
    if (a == b) return 0;
    if ((b - a) % c == 0) return (b - a) / c;
    L g = (b - a) % c;
    L m = maximum % c;
    L d = c - g;
    L n = solve(0, d, m, c);
    if (n == -1) return -1;
    // cout << "g=" << g << "m=" << m << "d=" << d << "n=" << n << endl;
    return (n * maximum + b - a) / c;
}


int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    L maximum = pow(2, k);
    if (b < a) b += maximum;
    long long res = solve(a, b, c, maximum);
    if (res < 0)
        cout << "Inf";
    else
        cout << res;
    // if (c == 0) {cout << "Inf"; return 0;}
    // if (a == b) {cout << 0; return 0;}
    // if ((b - a) % c == 0) {cout << (b - a) / c; return 0;}
    // uLL m = maximum % c, direct_gap = b - a;
    // if (m == 0) {
    //     cout << "Inf";
    //     return 0;
    // }
    // for (uLL n = 0; n < c; n++) {
    //     if ((n * m + direct_gap) % c == 0) {
    //         cout << "n= " << n << endl;
    //         cout << (maximum * n + direct_gap) / c;
    //         return 0;
    //     }
    // }
}
