#include <bits/stdc++.h>
using namespace std;
long long n, p, v, is_target[112345], power[112345], res;
int target_cnt, done[112345], cnt;
int main() {
    scanf("%lld %lld", &n, &p);
    v = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", is_target + i, power + i);
        target_cnt += is_target[i];
    }
    while (p > 0 and p <= n) {
        if (++cnt > 1e8) break;
        // cout << p << " " << v << endl;
        if (done[p]) {
            p += v;
            continue;
        }
        if (is_target[p]) {
            // cout << p << " " << power[p] << " " << v << endl;
            if (power[p] <= abs(v)) {
                res++;
                done[p] = 1;
                // power[p] = 2e15;
                if (--target_cnt == 0) break;
            }
        } else {
            if (v > 0)
                v = -(power[p] + v);
            else
                v = power[p] - v;
        }
        p += v;
    }
    cout << res << endl;
}

