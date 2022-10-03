#include <bits/stdc++.h>
using namespace std;
int a[500005], b[500005], n, q, l, r, f[500005][30];
stack<int> sa, sb, si;
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        while (!sa.empty()) {
            if (sa.top() == a[i] or sb.top() <= b[i]) {
                f[si.top()][0] = i;
                sa.pop();
                sb.pop();
                si.pop();
            } else
                break;
        }
        sa.push(a[i]);
        sb.push(b[i]);
        si.push(i);
    }
    // while (!si.empty()) {
    //     f[si.top()][0] = -1;
    //     si.pop();
    // }
    for (int j = 1, k = 1; k < n; j++, k <<= 1)
        for (int i = 1; i + k <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < 5; j++) cout << f[i][j] << " ";
    //     cout << endl;
    // }
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);
        int res = 1;
        // if (l==r) { puts("1"); continue; }
        while (l < r) {
            int found = -1;
            for (int j = 0; f[l][j] > 0 and f[l][j] <= r; j++) found = j;
            if (found == -1) break;
            res += (1 << found);
            l = f[l][found];
            // cout << "l=" << l << " found=" << found << endl;
        }
        printf("%d\n", res);
    }
}

