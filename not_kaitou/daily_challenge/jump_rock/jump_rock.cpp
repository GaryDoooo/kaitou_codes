#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, n, m;
    cin >> L >> n >> m;
    int d[50005] = {0}, l[50005], r[50005], g[n + 2];
    d[n + 1] = L;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        l[i] = i - 1;
        r[i] = i + 1;
        g[i ] = d[i] - d[l[i]];
    }
    g[n + 1] = L - d[n];
    g[0] = 1000000001;
    l[n + 1] = n;
    r[n + 1] = 0;
    l[0] = 0;
    for (int i = 0; i < m; i++) {
        int index = min_element(g, g + n + 2) - g;
        int left = l[index], right = r[index];
        if (g[left] < g[right]) {
            right = index;
            index = left;
            left = l[left];
        }
        g[right] += g[index];
        l[right] = left;
        r[left] = right;
        g[index] = 1000000001;
    }
    cout << min( *min_element(g, g + n + 2), L);
    return 0;
}