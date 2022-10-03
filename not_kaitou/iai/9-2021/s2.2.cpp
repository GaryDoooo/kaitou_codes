#include <iostream>
using namespace std;
int idx = 0, a[7005], r[7005][7005], s = 1, sum[7005];
int mod = 1e9 + 7, max_lvl[7005] = {1}, has_f = 0, n;
int main() {
    cin >> n;
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (has_f) {
            if (input == "f") {
                has_f++;
            } else {
                a[idx++] = has_f;
                has_f    = 0;
            }
        } else {
            if (input == "f")
                has_f = 1;
            else
                a[idx++] = 0;
        }
    }
    for (int i = 1; i < idx; i++) max_lvl[i] = s = s + a[i - 1];
    for (int i = 1; i <= max_lvl[idx - 1]; i++) r[idx - 1][i] = 1;
    for (int i = idx - 2; i >= 0; i--) {
        s = 0;
        for (int j = 1; j <= max_lvl[i + 1]; j++) {
            s      = (s + r[i + 1][j]) % mod;
            sum[j] = s;
        }
        for (int j = 1; j <= max_lvl[i]; j++) r[i][j] = sum[j + a[i]];
    }
    cout << r[0][1] % mod;
}
