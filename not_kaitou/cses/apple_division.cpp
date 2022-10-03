#include <bits/stdc++.h>
using namespace std;
int n, a[24], pick[24];
long long sum = 0, res = 1e18;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int k = 0; k < (1 << n) ; k++) {
        int temp = k;
        long long sum2 = 0;
        for (int j = 0; j < n; j++) {
            if (temp & 1) sum2 += a[j];
            temp >>= 1;
        }
        res = min(res, abs((sum2 << 1) - sum));
    }
    cout << res << endl;
}
