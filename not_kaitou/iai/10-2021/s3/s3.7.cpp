#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
struct num {
    long long s;
    int i;
    bool operator<(const num &b) const {
        return (s < b.s) or (s == b.s && i < b.i);
    }
};
int main() {
    int n = read(), m = read();
    num a[n];
    long long res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += read() - m;
        res += (sum >= 0);
        a[i] = {sum, i};
    }
    sort(a, a + n);
    int prev[n], next[n], largest_smaller[n], f[n], lookup[n];
    for (int i = 0; i < n; i++) lookup[a[i].i] = i;
    memset(largest_smaller, 255, sizeof(largest_smaller));
    for (int i = 0; i < n; i++) prev[i] = i - 1, next[i] = i + 1;
    for (int i = n - 1; i >= 0; i--) {
        int idx              = a[i].i;
        largest_smaller[idx] = prev[idx];
        if (next[idx] < n) prev[next[idx]] = prev[idx];
        if (prev[idx] >= 0) next[prev[idx]] = next[idx];
    }
    for (auto i : a) {
        if (largest_smaller[i.i] == -1) {
            f[i.i] = 0;
        } else {
            f[i.i] = f[largest_smaller[i.i]] + 1;
            for (int j = lookup[largest_smaller[i.i]] + 1; j < lookup[i.i]; j++)
                f[i.i] += (a[j].i <= i.i);
            res += f[i.i];
        }
    }
    cout << res << endl;
}
