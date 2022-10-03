#include <iostream>
using namespace std;
int a[105], sum[105];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = -1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = max(ans, sum[j] - sum[i - 1]);
        }
    }
    cout << ans;
    return 0;
}
