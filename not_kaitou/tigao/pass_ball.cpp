#include <bits/stdc++.h>
using namespace std;
__int128 f[31] = {1};
__int128 step_combination(int a, int b) { return f[a + b] / f[a] / f[b]; }
int main() {
    int n, m;
    cin >> n >> m;
    __int128 fratorial = 1;
    for (int i = 1; i <= 30; i++) fratorial *= i, f[i] = fratorial;
    __int128 res = 0;
    if (m % 2 == 0) res = step_combination(m / 2, m / 2);
    for (int i = n; i <= m; i += n) {
        if ((m - i) & 1) continue;
        res += 2 * step_combination((m - i) / 2, i + (m - i) / 2);
    }
    vector<int> res_digits;
    while (res > 0) {
        res_digits.push_back(res % 10);
        res /= 10;
    }
    if (res_digits.size() == 0) res_digits.push_back(0);
    for (int i = res_digits.size() - 1; i >= 0; i--) cout << res_digits[i];
}

