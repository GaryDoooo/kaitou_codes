#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, q, a, b, c, x[212345], cnt = 1;
ll s[212345], res;
set<pair<int, int>> changes[212345];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", x + i);
        s[i] = s[i - 1] + x[i];
    }
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &a, &b, &c);
            changes[a].insert(make_pair(b, c));
        } else if (a == 2) {
            scanf("%d%d%d", &a, &b, &c);
            res = s[c] - s[b - 1];
            for (auto it = changes[a].lower_bound(make_pair(b, 0));
                 it != changes[a].end(); it++)
                if (it->first > c)
                    break;
                else
                    res += it->second - x[it->first];
            printf("%lld\n", res);
        } else {
            scanf("%d", &a);
            changes[++cnt].insert(changes[a].begin(), changes[a].end());
        }
    }
}
