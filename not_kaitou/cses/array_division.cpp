#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k, a;
ll s[212345];
bool check(ll m) {
    // cout << endl << m << endl;
    int left = 0;
    for (int i = 0; i < k; i++) {
        // cout << left << " " << s[left] << " ";
        ll right_sum = s[left] + m;
        auto it      = upper_bound(s, s + n + 1, right_sum);
        // cout << *it << endl;
        if (it == s + n + 1) return true;
        if (left == distance(s, --it)) return false;
        left = distance(s, it);
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        s[i] = s[i - 1] + a;
    }
    ll left = 0, right = s[n];
    while (left < right) {
        // cout << "left right" << left << " " << right << endl;
        ll mid = left + right >> 1;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
}

