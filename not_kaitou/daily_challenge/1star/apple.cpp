#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], minimum = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        minimum = min(minimum, a[i]);
    }
    long long sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= minimum) continue;
        sum += a[i];
        cnt++;
    }
    printf("%0.1f\n", (double)sum / cnt);
}

