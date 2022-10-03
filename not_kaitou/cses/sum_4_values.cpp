#include <bits/stdc++.h>
using namespace std;
int n, x, a[1123];
struct node {
    int s, l, r;
};
vector<node> s;
bool operator<(const node& a, const node& b) { return a.s < b.s; }
int main() {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x) continue;
        for (int j = i + 1; j <= n; j++) {
            int sum = a[j] + a[i];
            if (sum >= x) continue;
            s.push_back({sum, i, j});
        }
    }
    sort(s.begin(), s.end());
    for (auto i : s) {
        int gap  = x - i.s;
        node tmp = {gap};
        auto it  = lower_bound(s.begin(), s.end(), tmp);
        if (it == s.end()) continue;
        for (; it != s.end(); ++it) {
            if (it->s > gap) break;
            if (it->l != i.l and it->r != i.r and it->l != i.r and
                it->r != i.l) {
                printf("%d %d %d %d\n", i.l, i.r, it->l, it->r);
                return 0;
            }
        }
    }
    puts("IMPOSSIBLE");
}

