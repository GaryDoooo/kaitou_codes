#include <bits/stdc++.h>
using namespace std;

long long solve(string s) {
    static int b[312345], e[312345];  //,n;// a[312345], n;
    int be_cnt = 0, q[8];             // b 1;  e 2;  s 3;  s 4;  i 5;  e 6
    memset(q, 0, sizeof(q));
    int n = s.size();
    // putchar('\n');
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        // putchar(c);
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
    cout << be_cnt << endl;
    // for (int i = 1; i <= be_cnt; i++) cout << b[i] << " " << e[i] << endl;
    long long res = 0;
    if (be_cnt == 0) return 0;
    struct be {
        int b, e, h, t;
    };  // position of Begin and End, non-Bessie chars before
    // this Bessie is head, to the head of the whole string, or the one char
    // right of the left Bessie's head; tail is to the end of the whole string,
    // or the one char left of the right Bessie's end
    be dbe[112345];     // disconnected Bessie groups;
    be mid_be[112345];  // those Bessie overlaps with disconnected Bessies
    int dbe_cnt = 0, mid_be_cnt = 0;
    dbe[++dbe_cnt] = {b[1], e[1], b[1], 0};
    for (int i = 2; i <= be_cnt; i++) {
        if (b[i] < dbe[dbe_cnt].e) {
            mid_be[++mid_be_cnt] = {b[i], e[i], dbe[dbe_cnt].b - b[i], 0};
        } else {
            dbe[++dbe_cnt]     = {b[i], e[i], b[i] - dbe[dbe_cnt - 1].b, 0};
            dbe[dbe_cnt - 1].t = e[i] - dbe[dbe_cnt - 1].e;
            if (mid_be_cnt > 0 and mid_be[mid_be_cnt].t > b[i])
                mid_be[mid_be_cnt].t = e[i] - mid_be[mid_be_cnt].e;
        }
    }
    dbe[dbe_cnt].t = n + 1 - dbe[dbe_cnt].e;
    // if (mid_be[mid_be_cnt].t == 0)  // if mid Bessie is the last Bessie
    //     mid_be[mid_be_cnt].t = n + 1 - mid_be[mid_be_cnt].e;
    long long ts[212345];     // tail sum of the disconnected Bessie's tails
    long long ts_ts[212345];  // tail sum of of the tail sum
    ts[dbe_cnt + 1] = ts_ts[dbe_cnt + 1] = 0;
    for (int i = dbe_cnt; i > 0; i--) ts[i] = ts[i + 1] + dbe[i].t;
    // which is the  Tn * n + T(n-1)*(n-1) ....T2*2+ T1
    for (int i = dbe_cnt; i > 0; i--) ts_ts[i] = ts_ts[i + 1] + ts[i];
    // (1*tail1+2*tail2+3*tail3)head1; head2(1*tail2+2*tail3); head3(1*tail3);
    //
    for (int i = 1; i <= dbe_cnt; i++) res += (long long)dbe[i].h * ts_ts[i];
    // add all middle Bessie's head*tail
    // for (int i = 1; i <= mid_be_cnt; i++) res += mid_be[i].h * mid_be[i].t;
    // cout << res << endl;
    // cout << dbe_cnt << " " << mid_be_cnt << endl;
    // for (int i = 1; i <= dbe_cnt; i++) {
    //     cout << dbe[i].h << " " << dbe[i].t << " " << ts[i] << " " <<
    //     ts_ts[i]
    //          << endl;
    // }
    // cout << "res = " << res << endl;
    return res;
}

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
    long long res  = solve(s);
    int chain_head = 0, chain_cnt = 0, chain_tail = 0;
    for (int i = 2; i <= be_cnt; i++) {
        if (b[i] < e[i - 1]) {
            if (chain_cnt == 0) {
                chain_head = b[i - 1] + 1;
                chain_cnt  = 2;
                // cout << "head " << chain_head << endl
                //      << s.substr(b[i - 1] - 1, e[i - 1] - b[i - 1] + 1) <<
                //      endl
                //      << s.substr(b[i] - 1, e[i] - b[i] + 1) << endl
                //      << s.substr(b[i + 1] - 1, e[i + 1] - b[i + 1] + 1) <<
                //      endl;
            } else
                chain_cnt++;
        } else if (chain_cnt > 0) {
            if (chain_cnt & 1) chain_tail = e[i - 1] - 1;
            // else if (i == be_cnt)
            //     chain_tail = n;
            else
                chain_tail = e[i] - 1;
            // res += solve(chain_head, chain_tail);
            cout << "count " << chain_cnt
                 << " ";  //<< "head " << chain_head << "tail "
            //      << chain_tail << endl;
            string tmp = s.substr(chain_head - 1, chain_tail - chain_head + 1);
            res += solve(tmp);
            chain_cnt = 0;
        }
    }
    if (chain_cnt > 0) {
        if (chain_cnt & 1)
            chain_tail = e[be_cnt] - 1;
        else
            chain_tail = n;
        string tmp = s.substr(chain_head - 1, chain_tail - chain_head + 1);
        res += solve(tmp);
    }
    cout << be_cnt << endl;
    printf("%lld\n", res);
}
