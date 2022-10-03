#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], sum = 0, acc[n], half_sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    sort(a, a + n);
    acc[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (half_sum)
            acc[i] = half_sum + a[i];
        else {
            acc[i] = a[i] + acc[i - 1];
            if (acc[i] >= sum / 2) half_sum = acc[i - 1];
        }
    }
    vector<int> can_sum(sum, 0);
    can_sum[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = acc[i]; j >= a[i]; j--)
            if (can_sum[j - a[i]]) can_sum[j] = 1;
    }
    for (int target = (sum & 1 ? sum / 2 + 1 : sum / 2); target <= sum;
         target++) {
        if (can_sum[target]) {
            cout << target;
            return 0;
        }
    }
}
