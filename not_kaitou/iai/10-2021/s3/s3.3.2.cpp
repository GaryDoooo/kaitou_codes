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
    long long res = 0, sum = 0;  //, s[n + 1], reserve_max;
    // int reserve_start         = 0;
    multiset<long long> Btree;
    for (int i = 2; i <= n; i++) {
        sum += read() - m;
        // if (reserve_start and sum >= s[i - 1]) {
        //     res += (sum >= 0) + (i - 1);
        //     cout << i - reserve_start << endl;
        //     continue;
        // }
        // if (reserve_start) {
        //     Btree.insert(s + reserve_start, s + i);
        //     reserve_start = 0;
        // }
        auto it = Btree.upper_bound(sum);
        // if (distance(it, Btree.end()) == 0) {
        //     res += (sum >= 0) + (i - 1);
        //     reserve_start = i;
        // } else {
        res += distance(Btree.begin(), it) + (sum >= 0);
        Btree.insert(sum);
        // }
        // cout << reserve_start << endl;
    }
    cout << res << endl;
}
