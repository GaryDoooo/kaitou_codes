#include <iostream>
using namespace std;
int n, f[(int)1e6 + 5];
const int MOD = 1e9 + 7;
int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j > i) break;
            f[i] = (f[i] + f[i - j]) % MOD;
        }
    }
    cout << f[n] << endl;
}
