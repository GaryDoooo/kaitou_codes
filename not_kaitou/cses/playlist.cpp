#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int n, a, l, res;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        l    = max(l, m[a]);
        m[a] = i;
        res  = max(res, i - l);
    }
    cout << res << endl;
}

