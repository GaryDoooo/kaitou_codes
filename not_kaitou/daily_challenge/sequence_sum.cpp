#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum[n + 1];
    sum[0] = 0;
    for (register int i = 1; i <= n; i++) sum[i] = sum[i - 1] + i;
    int left = 0, right = 1;
    while (right <= n and left <= n) {
        while (sum[right] - sum[left] < n and right < n)right++;
        if (sum[right] - sum[left] == n and right > left + 1) {
            cout << left + 1 << " " << right << "\n";
        }
        left++;
    }
    return 0;
}