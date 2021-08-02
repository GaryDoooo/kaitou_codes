#include <iostream>
#include <cmath>
#include <string>
// #include <bits/stdc++.h>
typedef long long L;
using namespace std;

L solve(L a, L b, L c, L maximum) {
    if (c == 0) return -1;
    if ((b - a) % c == 0) return (b - a) / c;
    __int128 n = solve(0, c - (b - a) % c, maximum % c, c);
    if (n == -1) return -1;
    return (n * maximum + b - a) / c;
}

int main() {
    L a, b, c, k;
    cin >> a >> b >> c >> k;
    L maximum = pow(2, k);
    L res = solve(a, (b < a) ? b + maximum : b, c, maximum);
    cout << (res < 0 ? "Inf" : to_string(res));
}