#include <iostream>
#define mod 2147483648
#define ll unsigned long long
using namespace std;
ll f[4123];
int main() {
    int n;
    cin >> n;
    f[1] = 0;
    for (int i = 2; i <= n; i++) f[i] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = 1; j + i <= n; j++) {
            f[i + j] = (f[j] + (i >= j) + f[i + j]) % mod;
        }
    }
    for (int i = 1; i <= n; i++) cout << f[i] << endl;
    cout << f[n];
}

