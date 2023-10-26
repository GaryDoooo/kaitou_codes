#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    static int b[312345], e[312345];  //,n;// a[312345], n;
    static int be_cnt, q[8], n;       // b 1;  e 2;  s 3;  s 4;  i 5;  e 6
    n = s.size();
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        if (c == 'b') {
            q[1] = i;
        } else if (c == 'e') {
            q[2] = max(q[2], q[1]);
            if (q[5] > 0) {
                if (q[5] > b[be_cnt]) {
                    b[++be_cnt] = q[5];
                    e[be_cnt]   = i;
                }
                q[5] = 0;
            }
        } else if (c == 's') {
            if (q[3] == 0) {
                q[3] = q[2];
            } else {
                q[4] = q[3];
                q[3] = q[2];
            }
        } else if (c == 'i')
            q[5] = max(q[5], q[4]);
    }
    long long res = 0;  //  = solve(s);
    b[0] = 0, e[be_cnt + 1] = n + 1;
    for (int i = 1; i <= be_cnt; i++) {
        long long cnt = 0, p = 0;
        long long h = b[i] - b[i - 1];
        for (int j = i; j <= be_cnt; j++) {
            if (b[j] > p) {
                p = e[j];
                cnt++;
            }
            res += h * cnt * (e[j + 1] - e[j]);
        }
    }
    printf("%lld\n", res);
}
