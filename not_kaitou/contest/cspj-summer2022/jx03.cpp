#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        scanf("%d%d", &n, &s);
        int a, sum[n + 1];
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            sum[i] = sum[i - 1] + a;
        }
        if (sum[n] < s) {
            puts("-1");
            continue;
        }
        int left = n, res = n;
        for (int i = n; sum[i] >= s; i--) {
            while (sum[left] > sum[i] - s and left > 0) left--;
            while (sum[left - 1] == sum[left] and left > 0) left--;
            res = min(res, n - i + left);
            // cout << i << " " << left << endl;
        }
        printf("%d\n", res);
    }
}

