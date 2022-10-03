#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> b(4e6 + 405, 2e9), p(4e6 + 405, 0);
int main() {
    cin >> n >> m;
    int t, i, waiting, tmax = 0;
    int people_cnt = 0;  // cnt from t-3m sec to t-1 sec
    for (i = 0; i < n; i++) {
        cin >> t;
        t += 300;  // t-3*m no seg error
        p[t]++;
        tmax = max(tmax, t);
    }
    for (i = 0; i <= 300; i++) b[i] = 0;
    for (t = 301; t < tmax + m; t++) {
        people_cnt += p[t - 1] - p[t - m * 3];
        if (people_cnt == 0) {
            b[t] = b[t - m];
            continue;
        }
        waiting = 0;
        for (i = t; i > t - m; i--) waiting += p[i] * (t - i);
        for (i = t - m; i > t - (m << 1); i--) {
            b[t] = min(b[t], waiting + b[i]);
            waiting += p[i] * (t - i);
        }
    }
    cout << *min_element(b.begin() + tmax, b.begin() + tmax + m);
}

