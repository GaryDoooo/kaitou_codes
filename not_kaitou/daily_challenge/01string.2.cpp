#include <bits/stdc++.h>
using namespace std;
long long count(int n) {
    if (n < 3) return 1 << n;
    int max_substr_len = n / 3;
    long long res = 1 << n;
    for (int substr_len = 1; substr_len <= max_substr_len; substr_len++) {
        for (int substrX3_start = 0; substrX3_start + substr_len * 3 <= n; ++substrX3_start) {
            int end_part_len = n - substr_len * 3 - substrX3_start;
            res -= count(substrX3_start) * count(end_part_len) * count(substr_len);
            if (end_part_len >= substr_len) res += count(substr_len);
            if (end_part_len > substr_len) res += count(substr_len);
        }
    }
    return res;
}
int main() {
    int n; cin >> n;
    cout << count(n) << endl;
}