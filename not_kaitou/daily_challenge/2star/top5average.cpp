#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    double s = 0;
    for (int i = n - 5; i < n; i++) s += a[i];
    printf("%.1f", s / 5);
}
