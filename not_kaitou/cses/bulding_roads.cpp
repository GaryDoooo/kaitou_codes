#include <bits/stdc++.h>
using namespace std;
int n, m, g[112345], a, b, r[112345], cnt;
int get_root(int x) {
    int in = x;
    while (g[x]) x = g[x];
    if (in != x) g[in] = x;
    return x;
}
void combine(int x, int y) {
    int rx = get_root(x), ry = get_root(y);
    if (rx != ry) g[x] = g[rx] = ry;
}
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        combine(a, b);
    }
    // set<int> s;
    // for (int i = 1; i <= n; i++) s.insert(get_root(i));
    // vector<int> v(s.begin(), s.end());
    // printf("%d\n", s.size() - 1);
    // for (int i = 0; i < s.size() - 1; i++) printf("%d %d\n", v[i], v[i + 1]);
    for (int i = 1; i <= n; i++)
        if (g[i] == 0)  // root node g is zero
            r[cnt++] = i;
    printf("%d\n", cnt - 1);
    for (int i = 0; i < cnt - 1; i++) printf("%d %d\n", r[i], r[i + 1]);
}

