#include <bits/stdc++.h>
using namespace std;
int n;
long long a[11234];
int o[11234];

int main() {
    scanf("%d", &n);
    set<long long> s;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s.insert(a[i]);
    }
    n     = s.size();
    int i = 0;
    for (long long j : s) a[++i] = j;
    long long max_L = a[1] / 4;
    long long res   = 0;
    if (n > 3) max_L = min(max_L, a[4] - a[1]);
    // cout << max_L << endl;
    vector<long long> ans;
    for (long long i = max_L; i > 0; i--) {
        int out = 0;
        // for (long long j : ans)
        //     if (j % i == 0) {
        //         out = 1;
        //         break;
        //     }
        // if (out) {
        //     res += i;
        //     continue;
        // }
        if (o[i]) continue;
        out = 0;
        unordered_set<long long> mod;
        for (long long j : s) {
            mod.insert(j % i);
            if (mod.size() > 3) {
                out = 1;
                break;
            }
        }
        if (out) continue;
        // if (mod.size() <= 3)
        res += i;
        for (int ii = 2; ii <= sqrt(i); ii++) {
            if (i % ii == 0) {
                if (o[ii] == 0) {
                    res += ii;
                    o[ii] = 1;
                }
                if (ii != sqrt(i)) {
                    if (o[i / ii] == 0) {
                        res += i / ii;
                        o[i / ii] = 1;
                    }
                }
            }
        }
    }
    printf("%lld\n", res);
}

