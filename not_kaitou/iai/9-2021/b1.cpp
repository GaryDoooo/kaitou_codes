#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, t = 0;
    cin >> n >> k;
    while (n > 2 * k) {
        n -= k;
        t += 2;
    }
    // cout << t << " " 
    // << n;
    if (n <= k)
        cout << t + 2;
    else if (n <= k / 2 + k)
        cout << t + 3;
    else
        cout << t + 4;
}

