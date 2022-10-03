#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int i_picked[1000005], j_cnt, i_cnt, res, o_picked[1000005];
// map<char, vector<int>> m;
queue<int> available_tailing_i;
int n;
int main() {
    scanf("%d\n", &n);
    scanf("%s\n", a);
    // for (int i = 0; i < n; i++) m[a[i]].push_back(i);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 'I')
            available_tailing_i.push(i);
        else if (a[i] == 'O') {
            if (available_tailing_i.size()) {
                i_picked[available_tailing_i.front()] = 1;
                o_picked[i] = available_tailing_i.front();
                available_tailing_i.pop();
            }
        }
    }
    set<int> oi_left, ioi;  // IOI's 2nd i position
    for (int i = 0; i < n; i++) {
        if (a[i] == 'I' and !i_picked[i])
            i_cnt++;
        else if (a[i] == 'J')
            j_cnt++;
        else if (a[i] == 'O' and o_picked[i]) {
            if (j_cnt) {
                res++;
                j_cnt--;
            } else if (i_cnt) {
                res++;
                i_cnt--;
                ioi.insert(o_picked[i]);
            } else
                oi_left.insert(i);
        }
    }
    if (oi_left.size() > 1) {
        // int last_oi;
        multiset<int> o_available;
        for (int i : oi_left) {
            if (o_available.empty()) {
                o_available.insert(i);
                continue;
            }
            if (o_picked[*o_available.begin()] < i) {
                o_available.erase(o_available.begin());
                res++;
            } else {
                o_available.insert(i);
            }
        }
        if (o_available.size() > 1 and ioi.size()) {
            vector<int> osa2(o_available.begin(), o_available.end());
            for (int i = 0; i + 1 < osa2.size(); i++)
                if (*ioi.begin() < osa2[i]) {
                    ioi.erase(ioi.begin());
                    res++;
                    i++;
                }
        }
    }
    cout << res << endl;
}

