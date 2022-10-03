#include <iostream>
using namespace std;
int n, a, s, r[212345];
long long res;
int main() {
    cin >> n;
    r[0]      = 1;
    int adder = (int)1e9 + (n - (int)1e9 % n);
    // cout << adder << endl;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s = (adder + s + a) % n;
        // cout << s << " ";
        // int diff = (n - s) % n;
        res += r[s];
        r[s]++;
        // cout << diff << " " << res << " " << r[s] << endl;
    }
    cout << res << endl;
}
