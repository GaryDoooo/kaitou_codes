#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int n, n0, m;
struct node {
    ll s;             // sum of all nodes
    ll ss;            // max sub array sum in this tree
    ll psMax, psMin;  // the max and min prefix sum in this tree
};
node t[812345];

void update(int i) {
    int l = i * 2, r = i * 2 + 1;
    t[i].s     = t[l].s + t[r].s;
    t[i].psMax = max(t[l].psMax, t[r].psMax + t[l].s);
    t[i].psMin = min(t[l].psMin, t[r].psMin + t[l].s);
    t[i].ss    = max(max(t[l].ss, t[r].ss), t[l].s + t[r].psMax - t[l].psMin);
}

void assign(int i) {
    t[i].s  = read();
    t[i].ss = t[i].psMax = max(0LL, t[i].s);
    t[i].psMin           = min(0LL, t[i].s);
}

int main() {
    n = read(), m = read();
    n0 = (1 << (int)trunc(log2(n - 1)) + 1) - 1;
    for (int i = n0 + 1; i <= n0 + n; i++) assign(i);
    for (int i = n0; i > 0; i--) update(i);
    while (m--) {
        int i = read() + n0;
        assign(i);
        while (i > 1) {
            i = i / 2;
            update(i);
        }
        printf("%lld ", t[1].ss);
    }
}
