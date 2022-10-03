#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n, q, a, b, c, x[212345], father[212345], done[212345], cnt = 1;
int create_time[212345];
ll s[212345], res;
struct ch {
    int time_stamp, a, x;
};
bool operator<(const ch& a, const ch& b) { return a.a < b.a; }
set<ch> changes[212345];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", x + i);
        s[i] = s[i - 1] + x[i];
    }
    memset(done, 127, sizeof(done));
    create_time[1] = q + 1;
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &a, &b, &c);
            changes[a].insert({q, b, c});
        } else if (a == 2) {
            scanf("%d%d%d", &a, &b, &c);
            // cout << a << " " << b << " " << c << endl;
            res          = s[c] - s[b - 1];
            int deadline = 0;
            while (a) {
                for (auto it = changes[a].lower_bound({0, b, 0});
                     it != changes[a].end(); it++)
                    if (it->a > c)
                        break;
                    else if (it->time_stamp < deadline)
                        continue;
                    else if (q != done[it->a]) {
                        res += it->x - x[it->a];
                        done[it->a] = q;
                    }
                deadline = create_time[a];
                a        = father[a];
            }
            printf("%lld\n", res);
        } else {
            scanf("%d", &a);
            father[++cnt]    = a;
            create_time[cnt] = q;
        }
    }
}
