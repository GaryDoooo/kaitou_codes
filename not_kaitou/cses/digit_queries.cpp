#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long> digits_count{0}, pow10;
int main() {
    unsigned long long n = 0, k = 1;
    for (int i = 0; i < 18; i++) {
        n += (k * 10 - k ) * (i + 1);
        digits_count.push_back(n);
        pow10.push_back(k);
        k *= 10;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        int lvl = distance(digits_count.begin(), lower_bound(digits_count.begin(), digits_count.end(), k));
        k -= digits_count[lvl - 1] + 1;
        unsigned long long num = pow10[lvl - 1];
        num += k / lvl;
        string s = to_string(num);
        cout << s[k % lvl] << endl;
        // int digit=k%lvl;
    }
}
