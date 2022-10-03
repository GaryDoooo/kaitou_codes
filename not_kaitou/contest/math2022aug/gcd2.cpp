#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
ull n, l, r, x, res;
ull gcd(ull a, ull b) {
    if (a < b) swap(a, b);
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> x;
        ull head = trunc(l / x), tail = trunc(r / x);
        cout << (head == tail ? head : 1) << endl;
    }
}
