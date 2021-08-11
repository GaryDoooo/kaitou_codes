#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int n = read();
    int a[n];
    for (int i = 0; i < n; i++) a[i] = read();
    sort(a, a + n);
    double midpoint = (a[0] + a[n - 1]) / 2;
    auto it = lower_bound(a, a + n, midpoint);
    it += (*it < midpoint);
    long long sum = 0;
    for (auto i = it - a; i < n; i++)
        sum += a[i];
    cout << sum / (n - (it - a)) << endl;
    return 0;
}