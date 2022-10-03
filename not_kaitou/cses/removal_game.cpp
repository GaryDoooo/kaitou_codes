#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, x[5123], pick[5123][5123];
ll f[5123][5123];
ll score(int l, int r, int *side) {
    if (l == r) return x[l];
    if (l > r) return 0;
    if (f[l][r] > -2e18) {
        *side = pick[l][r];
        return f[l][r];
    }
    int opponent_pick, temp;  // 0 left 1 right
    ll res, res1;
    score(l + 1, r, &opponent_pick);
    if (opponent_pick)
        res = x[l] + score(l + 1, r - 1, &temp);
    else
        res = x[l] + score(l + 2, r, &temp);
    score(l, r - 1, &opponent_pick);
    if (opponent_pick)
        res1 = x[r] + score(l, r - 2, &temp);
    else
        res1 = x[r] + score(l + 1, r - 1, &temp);
    if (res > res1) {
        *side = pick[l][r] = 0;
        return f[l][r]     = res;
    } else {
        *side = pick[l][r] = 1;
        return f[l][r]     = res1;
    }
}

int main() {
    scanf("%d", &n);
    memset(f, 128, sizeof(f));
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    cout << score(1, n, x + 5005) << endl;
}
