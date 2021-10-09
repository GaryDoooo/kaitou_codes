#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
int main() {
    int n = read(), m = read();
    long long res = 0, sum = 0;  // read() - m, s[n + 1];//, reserve_max;
    // int reserve_start         = 0;
    multiset<long long> Bt[20];
    for (int i = 1; i <= n; i++) {
        sum += read() - m;
        int pick        = 0;
        double min_dist = 1e9;
        res += (sum >= 0);
        for (int j = 0; j < 20; j++) {
            if (Bt[j].empty()) {
                pick     = j;
                min_dist = 0;
                continue;
            }
            auto it = Bt[j].upper_bound(sum);
            res += distance(Bt[j].begin(), it);
            double dist =
                abs((int)(Bt[j].size() >> 1) - distance(Bt[j].begin(), it)) /
                Bt[j].size();
            if (dist < min_dist) {
                min_dist = dist;
                pick     = j;
            }
        }
        Bt[pick].insert(sum);
        // cout << i << endl;
    }
    cout << res << endl;
}
