#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned int x, a, b, res = 0;
    cin >> x >> a >> b;
    if (a < b) swap(a, b);
    for (int i = a; i < x; i += a) res += ((x - i) % b == 0 and x - i > b);
    cout << res << endl;
}
