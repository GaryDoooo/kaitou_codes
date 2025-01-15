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

// sort all the limits (lmt) in an order that ends lefter first
// and try to make the limits being met with the trees at the right side of the range as possible, which can be shared with future limit ranges.
// Using prefix sum to quickly decide how many trees are there in a range. 
//
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
    // sort the trees into orders, and make each limit range left and right side to sit on one tree. The left side sits to the left most tree in the range, 
    // while the right side of the range sits on the right most tree in the range. 
    sort(l, l + k, cmp_l);
    int l_idx = 0, ps[n + 1];
    memset(ps, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++) { // go through the ranges by order.
        if (i > 0)
            ps[i] = ps[i - 1]; // inherate prefix sum value from last position.
        while (l[l_idx].r == i and l_idx < k) {
            int range_sum;
            if (l[l_idx].l > 0)
                range_sum = ps[i] - ps[l[l_idx].l - 1];
            else
                range_sum = ps[i]; // count how many trees are currently in the range
            if (range_sum < l[l_idx].t) {
                int gap = l[l_idx].t - range_sum;
                int j = i;
                while (gap > 0) { // if not enough trees in the range, put trees on the right most available slots
                                  // which ps[i-1]==ps[i] means at position i there is no tree
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
    }
    cout << n - ps[n - 1] << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}
