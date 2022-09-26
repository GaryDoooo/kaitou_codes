#include <iostream>
#include <vector>
#define ll unsigned long long
using namespace std;
ll pow_of_9[19];
ll count(ll x) {
    if (x < 11) return x + 1;
    int digi_cnt = 0;
    ll xx        = x;
    vector<int> digits;
    while (xx) digi_cnt++, digits.push_back(xx % 10), xx /= 10;
    bool ok           = true;
    int same_digi_idx = 0;
    for (int i = 0; i + 1 < digits.size(); i++)
        if (digits[i] == digits[i + 1]) {
            ok            = false;
            same_digi_idx = i;
        }
    ll res = ok, l = 1;
    for (int i = 1; i < digits.size() - 1; i++) l *= 10;
    // cout << l << endl;
    for (ll i = 1, j = 0; i <= l; j++, i = i * 10) {
        res += pow_of_9[j];
        // cout << j << endl;
    }
    // if (l >= 10) res++;
    // cout << res << endl;
    for (int i = digits.size() - 1; i >= same_digi_idx; i--) {
        for (int j = 0; j < digits[i]; j++) {
            if (i < digits.size() - 1)
                if (j == digits[i + 1]) continue;
            res += pow_of_9[i];
        }
    }
    return res;
}
bool qualified(ll xx) {
    vector<int> digits;
    while (xx) {
        digits.push_back(xx % 10);
        xx /= 10;
    }
    // cout << digits.size() << " size" << endl;
    bool ok = true;
    for (int i = 0; i + 1 < digits.size(); i++)
        if (digits[i] == digits[i + 1]) ok = false;
    return ok;
}
int main() {
    pow_of_9[0] = 1;
    for (int i = 1; i < 19; i++) pow_of_9[i] = pow_of_9[i - 1] * 9;
    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a) + qualified(a);
    // ll inp;  //= 33433;
    // cin >> inp;
    // cout << count(inp) << endl;
    // int cnt = 0;
    // for (int ii = 0; ii <= inp; ii++) {
    //     // cout << ii << endl;
    //     int xx = ii;
    //     vector<int> digits;
    //     while (xx) {
    //         digits.push_back(xx % 10);
    //         xx /= 10;
    //     }
    //     // cout << digits.size() << " size" << endl;
    //     bool ok = true;
    //     for (int i = 0; i + 1 < digits.size(); i++)
    //         if (digits[i] == digits[i + 1]) ok = false;
    //     if (ok) {
    //         cnt++;
    //         // cout << ii << " ";
    //     }
    //     // int a1 = i % 10, a2 = (i / 10) % 10, a3 = i / 100;
    //     // if (a1 != a2 and a2 != a3) cnt++;
    // }
    // cout << endl << cnt << endl;
}
