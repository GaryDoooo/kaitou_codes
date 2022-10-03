#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    bool p[n + 5];
    memset(p, 1, sizeof(p));
    p[1] = 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) p[j] = 0;
        }
    }
    unsigned int sum = (m <= 2);
    for (int i = (m | 1); i <= n; i += 2) sum += p[i];
    cout << sum << endl;
}
