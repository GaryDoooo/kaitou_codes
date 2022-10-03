#include <bits/stdc++.h>
using namespace std;
int n, idx = 0, a[7005], r[7005][7005];
int mod = 1e9 + 7;
int max_lvl[7005];
long long res(int i, int lvl) {
    if (r[i][lvl] > 0) return r[i][lvl];
    if (i == idx - 1) return lvl;
    long long rr = 0;
    for (int j = 1; j <= lvl; j++) {
        rr = (rr + res(i + 1, j + a[i])) % mod;
    }
    r[i][lvl] = rr;
    return rr;
}
int main() {
    memset(r, 0, sizeof(r));
    int n;
    cin >> n;
    int has_f = 0;
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
    int sum    = 1;
    max_lvl[0] = 1;
    for (int i = 1; i < idx; i++) {
        sum += a[i - 1];
        max_lvl[i] = sum;
    }
    // cout << idx << endl;
    // for (int i = 0; i < idx; i++) cout << max_lvl[i] << " " << a[i] << endl;
    // cout << res(0, 1) << endl;
    for (int i = idx - 1; i >= 0; i--) {
        if (i == idx - 1) {
            for (int j = 1; j <= max_lvl[i]; j++) r[i][j] = 1;
        } else {
            int sum[max_lvl[i + 1]], s = 0;
            for (int j = 1; j <= max_lvl[i + 1]; j++) {
                s      = (s + r[i + 1][j]) % mod;
                sum[j] = s;
            }
            for (int j = 1; j <= max_lvl[i]; j++) r[i][j] = sum[j + a[i]];
        }
    }
    cout << r[0][1];
}
