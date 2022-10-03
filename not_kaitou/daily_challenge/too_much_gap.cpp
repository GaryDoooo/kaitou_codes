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
    int n = read(), k = read();
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = read();
    sort(v.begin(), v.end());
    long long res = 0;
    for (int i = n - 1; i > 0; i--) {
        res += (upper_bound(v.begin(), v.end(), v[i] - k) - v.begin());
    }
    cout << res << endl;
    return 0;
}
