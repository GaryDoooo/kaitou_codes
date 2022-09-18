#include <bits/stdc++.h>
using namespace std;
int n, w[30], x, res, result = 1e9;
struct node {
    int res;
    multiset<int> s;
};
// queue<node> q;
stack<node> stk;
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);
    // for (int i = 0; i < n; i++) cout << w[i] << " ";
    // cout << endl;
    multiset<int> s(w, w + n);
    stk.push({0, s});
    // q.push({0, s});
    while (!stk.empty()) {
        // cout << q.size() << endl;
        // s   = q.front().s;
        // res = q.front().res;
        // // cout << s.size() << " " << res << endl;
        // q.pop();
        s   = stk.top().s;
        res = stk.top().res;
        stk.pop();
        bool forked = false;
        while (!forked) {
            // cout << s.size() << endl;
            auto it = s.end();
            it--;
            int a = *it;
            // cout << " a=" << a << endl;
            // for (int i : s) cout << i << " ";
            // cout << endl;
            s.erase(it);
            if (s.empty()) {
                result = min(result, ++res);
                break;
            }
            // for (int i : s) cout << i << " ";
            // cout << endl;
            it = s.lower_bound(x - a);
            if (it == s.begin()) {
                if (*it == x - a) s.erase(it);
                res++;
                if (s.empty()) {
                    result = min(result, res);
                    break;
                }
                continue;
            }
            if (it != s.end())
                if (*it == x - a) {
                    s.erase(it);
                    res++;
                    if (s.empty()) {
                        result = min(result, res);
                        break;
                    }
                    continue;
                }
            it--;
            // cout << *it << " " << distance(it, s.begin()) << endl;
            // cout << "start here" << endl;
            if (x - a < (*s.begin()) * 2) {
                // cout << "keep" << endl;
                a += *it;
                s.erase(it);
                s.insert(a);
            } else {
                forked = true;
                node t = {res, s};
                t.s.erase(t.s.lower_bound(*it));
                t.s.insert(a + *it);
                stk.push(t);
                // q.push(t);
                // cout << "pushed q" << q.size() << endl;
                int last = *it;
                for (; it != s.begin(); it--) {
                    // cout << *it << " " << distance(s.begin(), it) << " in ";
                    // for (int i : s) cout << i << " ";
                    // cout << endl;
                    if (*it == last or *it + a + *s.begin() > x) continue;
                    last    = *it;
                    node tt = {res, s};
                    tt.s.erase(tt.s.lower_bound(*it));
                    tt.s.insert(a + *it);
                    stk.push(tt);
                    // q.push(tt);
                }
            }
        }
    }
    cout << result << endl;
}
