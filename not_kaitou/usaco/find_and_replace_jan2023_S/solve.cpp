#include <bits/stdc++.h>
using namespace std;

int t;

int convert(char c) {
    if (c >= 'a' and c <= 'z') return c - 'a' + 1;
    if (c >= 'A' and c <= 'Z') return c - 'A' + 27;
}

int solve(string &s1, string &s2) {
    int res   = 0;
    int e[55] = {0}, in[55] = {0}, in0[55];
    // cout << "length" << s1.length() << endl;
    int uniq = 0;
    if (s1.length() != s2.length()) return -1;
    if (s1 == s2) return 0;
    for (int i = 0; i < s1.length(); i++) {
        int c1 = convert(s1[i]), c2 = convert(s2[i]);
        if (e[c1] == 0) {
            e[c1] = c2;
            in[c2]++;
            uniq++;
        } else if (c2 != e[c1]) {
            // cout << "Error. replicating." << endl;
            return -1;
        }
    }
    // cout << "uniq" << uniq << endl;
    stack<int> s;
    memcpy(in0, in, sizeof(in));
    for (int i = 1; i <= 52; i++)
        if (in[i] == 0 and e[i] > 0) s.push(i);
    while (s.size() > 0) {
        int x = s.top();
        s.pop();
        if (e[x] > 0 and e[x] != x) res++;
        if ((--in[e[x]]) == 0) s.push(e[x]);
    }
    // cout << "res intermediate" << res << endl;
    int have_loop = 0;
    for (int i = 1; i < 52; i++)
        if (in[i] > 0) have_loop++;
    if (have_loop) {
        int have_0in = 0;
        for (int i = 1; i <= 52; i++)
            if (in[i] == 0) have_0in++;
        if (have_0in == 0) {
            // cout << "no zero in stack" << endl;
            return -1;
        }
    }
    // int loop = 0;
    for (int i = 1; i <= 52; i++)
        if (in[i] > 0 and e[i] != i) {
            // loop++;
            // res++;
            int have_in_branch = 0;
            int x              = i;
            do {
                x = e[x];
                if (in0[x] > 1) have_in_branch = 1;
                in[x]--;
                res++;
            } while (x != i);
            if (have_in_branch == 0) res++;
        }
    // cout << "Loop: " << loop << endl;
    return res;
}

int main() {
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        printf("%d\n", solve(s1, s2));
    }
}

