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
    int index, max_smaller_on_left = -1;
    bool operator<(const num &b) const {
        return (s < b.s) or (s == b.s && index < b.index);
    }
};
struct node {
    int prev, next;
};
int main() {
    int n = read(), m = read();
    num a[n];
    long long res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += read() - m;
        res += (sum >= 0);
        a[i].s = sum, a[i].index = i;
    }
    sort(a, a + n);
    node chain[n];
    int f[n], lookup[n];
    for (int i = 0; i < n; i++)
        chain[i] = {i - 1, i + 1}, lookup[a[i].index] = i;
    for (int i = n - 1; i >= 0; i--) {
        a[i].max_smaller_on_left = chain[a[i].index].prev;
        if (chain[a[i].index].next < n)
            chain[chain[a[i].index].next].prev = chain[a[i].index].prev;
        if (chain[a[i].index].prev >= 0)
            chain[chain[a[i].index].prev].next = chain[a[i].index].next;
    }
    for (int i = 0; i < n; i++) {
        if (a[i].max_smaller_on_left == -1) {
            f[a[i].index] = 0;
        } else {
            f[a[i].index] = f[a[i].max_smaller_on_left] + 1;
            for (int j = lookup[a[i].max_smaller_on_left] + 1;
                 j < lookup[a[i].index]; j++)
                f[a[i].index] += (a[j].index <= a[i].index);
            res += f[a[i].index];
        }
    }
    cout << res << endl;
}
