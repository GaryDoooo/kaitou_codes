#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n, t, k[212345];
bool work(ll time) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) cnt += time / k[i];
    return cnt >= t;
}
int main() {
    scanf("%lld%lld", &n, &t);
    for (int i = 0; i < n; i++) scanf("%lld", &k[i]);
    ll l = 0, r = 2e18;
    while (l < r) {
        // cout << l << " " << r << endl;
        ll m = l + r >> 1;
        if (work(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
}
