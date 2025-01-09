#include <bits/stdc++.h>
using namespace std;

struct lmt {
    int l, r, t;
};
lmt l[112345];

bool cmp_l(const lmt& a, const lmt& b) {
    if (a.r != b.r)
        return a.r < b.r;
    else
        return a.l > b.l;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &l[i].l, &l[i].r, &l[i].t);
        auto it = lower_bound(a.begin(), a.end(), l[i].l);
        l[i].l = distance(a.begin(), it);
        it = lower_bound(a.begin(), a.end(), l[i].r);
        if (it == a.end())
            l[i].r = n - 1;
        else if (*it > l[i].r)
            l[i].r = distance(a.begin(), it) - 1;
        else
            l[i].r = distance(a.begin(), it);
    }
    sort(l, l + k, cmp_l);
    int l_idx = 0, ps[n + 1];
    memset(ps, 0, sizeof(int) * (n + 1));
    // for (int i = 0; i < k; i++)
    //     cout << l[i].l << " " << l[i].r << " " << l[i].t << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0)
            ps[i] = ps[i - 1];
        while (l[l_idx].r == i and l_idx < k) {
            int range_sum;
            if (l[l_idx].l > 0)
                range_sum = ps[i] - ps[l[l_idx].l - 1];
            else
                range_sum = ps[i];
            // cout << range_sum << " " << l_idx << " " << l[l_idx].l << " "
            //      << l[l_idx].r << " " << l[l_idx].t << endl;
            if (range_sum < l[l_idx].t) {
                int gap = l[l_idx].t - range_sum;
                int j = i;
                while (gap > 0) {
                    int new_psj = ps[j] + gap;
                    if (j > 0)
                        gap -= (ps[j] == ps[j - 1]);
                    else
                        gap--;
                    ps[j--] = new_psj;
                }
            }
            l_idx++;
        }
        // cout << i << "->" << ps[i] << endl;
    }
    cout << n - ps[n - 1] << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}
