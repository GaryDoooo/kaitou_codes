#include <bits/stdc++.h>
#define INF 2123456789

using namespace std;
int main() {
    int m, n, k, d;
    cin >> m >>  k >> n;
    int a[100005] = {0};
    for (int i = 0; i < n; i++) {
        // read(d);
        cin >> d;
        a[d - 1] = 1;
    }
    int res = INF, missing = accumulate(a, a + k, 0);
    for (int i = k; i < m; i++) {
        missing = missing - a[i - k] + a[i];
        res = min(res, missing);
    }
    cout << res << endl;
    return 0;
}