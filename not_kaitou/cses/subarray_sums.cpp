#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, x, a;
ll res, s;
// unordered_
map<ll, int> m;
// multiset<ll> ss;
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
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar(' ');
}
int main() {
    n = read();
    x = read();
    // scanf("%d%d", &n, &x);
    // for (int i = 1; i <= n; i++) {
    //     scanf("%d", &a);
    //     s[i] = s[i - 1] + a;
    // }
    m[0] = 1;
    // ss.insert(0);
    for (int i = 1; i <= n; i++) {
        a = read();
        s += a;
        // cout << "i=" << i << "  s=" << s[i] << " ";
        ll diff = s - (ll)x;
        // auto it = ss.lower_bound(diff);
        res += m[diff];
        // cout << m[diff] << endl;
        m[s]++;
        // cout << "lower_bound=" << *it << " ";
        // if (it == ss.end() or *it != diff) {
        //     // cout << " done" << endl;
        //     ss.insert(s[i]);
        //     continue;
        // }
        // // if (*it != diff) continue;
        // auto it2 = ss.upper_bound(diff);
        // // cout << "upper_bound=" << *it2 << " ";
        // res += distance(it, it2);
        // // cout << "distance=" << distance(it, it2) << endl;
        // ss.insert(s[i]);
    }
    cout<< res << endl;
}
