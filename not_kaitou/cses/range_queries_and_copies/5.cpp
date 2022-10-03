#include <bits/stdc++.h>
#define ll long long
#define SNAP_STEP 500
using namespace std;
int n, q, a, b, c, x[212345], cnt = 1;
ll s[212345], res;
struct ch {
    int time_stamp, a, x;
};
bool operator<(const ch& a, const ch& b) { return a.a < b.a; }
struct sub_array {
    int father, create_time, depth;
    set<ch> changes;
} e[212345];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", x + i);
        s[i] = s[i - 1] + x[i];
    }
    e[1] = {0, q + 1, 0};
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &a, &b, &c);
            ///////////////////
            // if there is a same element in set
            // it just keeps the old one
            // This's important. Set old element has priority.
            // And set (not unordered_set) only looks at sorting order
            //
            e[a].changes.erase({q, b, c});
            e[a].changes.insert({q, b, c - x[b]});
        } else if (a == 2) {
            scanf("%d%d%d", &a, &b, &c);
            res = s[c] - s[b - 1];
            stack<pair<int, int>> ss;
            set<ch> temp;
            int deadline = 0;
            while (a) {
                for (auto it = e[a].changes.lower_bound({0, b, 0});
                     it != e[a].changes.end(); it++)
                    if (it->a > c)
                        break;
                    else if (it->time_stamp < deadline)
                        continue;
                    else
                        temp.insert(*it);
                if (e[a].depth % SNAP_STEP == 0) break;
                deadline = e[a].create_time, a = e[a].father;
            }
            for (auto i : temp) res += i.x;  // - x[i.a];
            printf("%lld\n", res);
        } else {
            scanf("%d", &a);
            e[++cnt] = {a, q, e[a].depth + 1};
            if (e[cnt].depth % SNAP_STEP == 0) {
                a = cnt;
                do {
                    a = e[a].father;
                    e[cnt].changes.insert(e[a].changes.begin(),
                                          e[a].changes.end());
                } while (e[a].depth % SNAP_STEP);
            }
        }
    }
}
