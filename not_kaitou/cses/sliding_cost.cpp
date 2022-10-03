#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n, k, a[212345], kk;
ll cost(int median, ll l, ll r) {
    return (ll)median * (kk)-l + r - (ll)(k - kk) * (ll)median;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int b[k];
    for (int i = 0; i < k; i++) b[i] = a[i];
    sort(b, b + k);
    kk = (k > 1 ? k + 1 >> 1 : 1);
    multiset<int> sl(b, b + kk), sr(b + kk, b + k);
    ll ls = 0, rs = 0;
    for (int i : sl) ls += i;
    for (int i : sr) rs += i;
    int median = b[kk - 1];
    cout << cost(median, ls, rs) << " ";  // << kk << " ";
    for (int i = k; i < n; i++) {
        if (a[i - k] <= median) {
            sl.erase(sl.lower_bound(a[i - k]));
            ls -= a[i - k];
        } else {
            sr.erase(sr.lower_bound(a[i - k]));
            rs -= a[i - k];
        }
        if (a[i] <= median) {
            sl.insert(a[i]);
            ls += a[i];
        } else {
            sr.insert(a[i]);
            rs += a[i];
        }
        while (sl.size() > kk) {
            auto it = sl.end();
            sr.insert(*(--it));
            rs += *it;
            ls -= *it;
            sl.erase(it);
        }
        while (sl.size() < kk) {
            sl.insert(*sr.begin());
            ls += *sr.begin();
            rs -= *sr.begin();
            sr.erase(sr.begin());
        }
        auto it = sl.end();
        printf("%lld ", cost(median = *(--it), ls, rs));
    }
}
