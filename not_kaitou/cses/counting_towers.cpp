#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll one[1123456], two[1123456];
int t, a, MOD = 1e9 + 7;
int main() {
    one[1] = 1, two[1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        one[i] = ((one[i - 1] << 2) + two[i - 1]) % MOD;
        two[i] = ((two[i - 1] << 1) + one[i - 1]) % MOD;
    }
    cin >> t;
    while (t--) {
        cin >> a;
        cout << (one[a] + two[a]) % MOD << endl;
    }
}
