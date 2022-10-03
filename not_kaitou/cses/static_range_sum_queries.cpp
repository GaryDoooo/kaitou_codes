#include <iostream>
using namespace std;
long long s[212345];
int n, a, t, b;
int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    while (t--) {
        cin >> a >> b;
        cout << s[b] - s[a - 1] << endl;
    }
}

