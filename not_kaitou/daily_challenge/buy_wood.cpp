#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &x, pair<int, int> &y) {
    return x.first > y.first;
}
int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> vendor[n];
    cin >> vendor[0].first >> vendor[0].second;
    for (int i = 1; i < n; i++) {
        vendor[i].first = ((vendor[i - 1].first * 37011 + 10193) % 10000) + 1;
        vendor[i].second = ((vendor[i - 1].second * 73011 + 24793) % 100) + 1;
    }
    sort(vendor, vendor + n, cmp);
    // for (auto i : vendor) {
    //     cout << i.first << " " << i.second << endl;
    // }
    for (int res = vendor[0].first; res > 0; res--) {
        int number = 0;
        for (int i = 0; i < n; i++) {
            if (vendor[i].first < res) break;
            number += vendor[i].second * (vendor[i].first / res);
            if (number > m) {
                cout << res;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}