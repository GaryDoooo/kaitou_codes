#include <bits/stdc++.h>
using namespace std;
__int128 abs(__int128 x) {
    if (x < 0) return -x;
    return x;
}
int main() {
    int n, p, v0, a;
    cin >> n >> p;
    vector<__int128> v(n);
    cin >> v0;
    __int128 existing_max = v0, continue_sum = v0;
    v[0] = v0;
    for (int i = 1; i < n; i++) {
        cin >> a;
        continue_sum = max((__int128)a, continue_sum + a);
        existing_max = max(existing_max, continue_sum);
        v[i]         = existing_max;
    }
    __int128 score = v[0], res = v[0], max_score_value = v[0] * 2;
    for (int i = 1; i < n; i++) {
        score           = max_score_value;
        res             = max(res, score);
        max_score_value = max(max_score_value, score + v[i]);
    }
    cout << (int)((res / abs(res)) * (abs(res) % p));
}
