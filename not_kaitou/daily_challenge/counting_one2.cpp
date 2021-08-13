#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res[1000005];
    int sum;//, n = 10;
    for (int j = 0; j <= 1000000; j++) {
        int k = j;
        while (k > 0) sum += (k % 10 == 1), k /= 10;
        res[j] = sum;
    }
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << res[b] - res[a - 1] << "\n";
    }
    return 0;
}