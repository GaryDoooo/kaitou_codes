#include <bits/stdc++.h>
using namespace std;
// struct gap {
//     int index, min_gap, total_gap;
// }
// bool cmp(const gap &a, const gap &b) {
//     return (a.min_gap < b.min_gap || (a.min_gap == b.min_gap and a.total_gap < b.total_gap));
// }
int main() {
    int L, n, m;
    cin >> L >> n >> m;
    int d[50005] = {0}, l[50005], r[50005], g[n + 2];
    d[n + 1] = L;
    // gap g[n];
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
    // for (int i = 0; i < n; i++) {
    // g[]
    // gap[i].index = i + 1;
    // int left_gap = d[i + 1] - d[i], right_gap = d[i + 2] - d[i + 1];
    // gap[i].total_gap = left_gap + right_gap;
    // gap[i].min_gap = min(left_gap, right_gap);
    // }
    // while (cin >> d[i])i++;
    // for (i = 0; i <= n ; i++) {gap[i] = d[i + 1] - d[i];}
    // // gap[0] = d[1];
    // for (auto j : g) cout << j << " ";
    // cout << endl;
    // // gap[n - 1] = l - d[n - 2];
    for (int i = 0; i < m; i++) {
        // sort(gap.begin(), gap.end(),cmp);
        // int index = g[0].index;
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
    //     int min_index = min_element(gap, gap + n + 1) - gap;
    //     // if (min_index > 0) gap[min_index - 1] += gap[min_index];
    //     int right = min_index + 1, left;
    //     if (min_index == n ) {right = min_index; min_index--;}
    //     else if (min_index > 0) {
    //         right = min_index + 1;
    //         left = min_index - 1;
    //         while (gap[left] > 1000000000 and left > 0) left--;
    //         while (gap[right] > 1000000000 and right <= n) right++;
    //         if (gap[right] > gap[left]) {
    //             right = min_index;
    //             min_index = left;
    //         }
    //     }
    //     gap[right] += gap[min_index];
    //     gap[min_index] = 1000000001;
    // }
    // for (auto j : g) cout << j << " ";
    // cout << endl;
    cout << min( *min_element(g, g + n + 2), L);
    return 0;
}