#include <bits/stdc++.h>
using namespace std;
int main() {
    register int n;
    cin >> n;
    if (n == 1) cout << 1;
    else if (n == 2) cout << 2;
    else {
        n = n - 2;
        register unsigned int a = 1, b = 1, c = 2, t;
        for (register int i = 0; i < n; i++) {
            t = (a + b + c) % 1000000007
                a = b; b = c; c = t;
        }
        cout << t;
    }
    return 0;
}