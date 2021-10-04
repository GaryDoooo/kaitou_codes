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
    long long res = 0, sum = 0, t1 = 0, t2 = 0, t3 = 0;
    int reserve_start = 0;
    multiset<long long> Btree, temp;
    for (int i = 1; i <= n; i++) {
        sum += read() - m;
        res += (sum > 0);
        auto it = Btree.upper_bound(sum);
        if (it == Btree.end()) {
            res += Btree.size();
            auto itt = temp.upper_bound(sum);
            res += distance(temp.begin(), itt);
            auto start = chrono::steady_clock::now();
            temp.insert(sum);
            auto end = chrono::steady_clock::now();
            t3 += chrono::duration_cast<chrono::microseconds>(end - start)
                      .count();
            if (temp.size() > 2000) {
                auto start = chrono::steady_clock::now();
                Btree.insert(temp.begin(), temp.end());
                temp.clear();
                auto end = chrono::steady_clock::now();
                t1 += chrono::duration_cast<chrono::microseconds>(end - start)
                          .count();
            }
        } else {
            auto start = chrono::steady_clock::now();
            res += distance(Btree.begin(), it);
            Btree.insert(sum);
            auto end = chrono::steady_clock::now();
            t2 += chrono::duration_cast<chrono::microseconds>(end - start)
                      .count();
        }
    }
    cout << res << endl;
    cout << t1 << endl << t2 << endl << t3 << endl;
}
