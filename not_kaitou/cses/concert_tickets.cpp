#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
////////////////////////

int main() {
    int n = read(), m = read();
    // multiset<int> p;
    vector<int> in(n);
    for (int i = 0; i < n; i++) in[i] = read();
    sort(in.begin(), in.end());
    // memcpy(&p, &in, sizeof(int) * n);
    // p.insert(read());
    // for (int i = 0; i < n / 2; i++) {
    //     p.insert(n / 2 + i);
    //     p.insert(n / 2 - 1);
    // }
    multiset<int> p(in.begin(), in.end());
    for (int i = 0; i < m; i++) {
        int a   = read();
        auto it = p.lower_bound(a);
        if (it == p.end()) {
            if (it == p.begin()) {
                printf("-1 ");
                continue;
            }
            it--;
        }
        if (*it > a) {
            if (it == p.begin()) {
                printf("-1 ");
                continue;
            }
            it--;
        }
        printf("%d ", *it);
        // cout << *it << endl;
        p.erase(it);
    }

    //// Wrong, time out
    // int p[n];
    // for (int i = 0; i < n; i++) p[i] = read() << 1;
    // sort(p, p + n);
    // for (int i = 0; i < m; i++) {
    //     int a   = read() << 1;
    //     auto it = upper_bound(p, p + n, a);
    //     if (it == p + n) it--;
    //     while (it != p and (*it > a or *it & 1)) it--;
    //     if (it == p and (*it > a or *it & 1))
    //         cout << -1 << endl;
    //     else {
    //         cout << (*it >> 1) << endl;
    //         *it = *it | 1;
    //     }
    // }
    /// Wrong... not the buyers come in order
    // struct buyer {
    //     int pay, order;
    //     bool operator<(const buyer& other) const { return pay < other.pay; };
    // };
    // buyer b[m];
    // for (int i = 0; i < m; i++) b[i] = {read(), i};
    // sort(b, b + m);
    // int p_index = n - 1, b_index = m - 1;
    // int res[m];
    // while (b_index >= 0) {
    //     if (p_index == -1) {
    //         res[b[b_index--].order] = -1;
    //         continue;
    //     }
    //     while (p[p_index] > b[b_index].pay and p_index > 0) p_index--;
    //     if (p_index == 0 and p[p_index] > b[b_index].pay)
    //         res[b[b_index--].order] = -1;
    //     else {
    //         res[b[b_index--].order] = p[p_index--];
    //     }
    // }
    // for (int i : res) cout << i << endl;
}
