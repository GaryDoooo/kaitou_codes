#include <bits/stdc++.h>
using namespace std;
int main() {
    register int n, res = 0;
    cin >> n;
    for (register int i = n; i >= 0; i -= 3) {
        res += i / 2 + 1;
    }
    cout << res;
}