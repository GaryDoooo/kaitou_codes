#include <bits/stdc++.h>
using namespace std;
struct node {
    int person_left, lifts, picked, current_load, last_pick;
    friend bool operator<(const node& a, const node& b) {
        return tie(a.lifts, a.person_left, a.current_load) <
               tie(b.lifts, b.person_left, b.current_load);
    }
};
multiset<node> q;
int n, x, w[22];
int main() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    sort(w, w + n);
    q.insert({n - 1, 0, 1, w[0], 0});
    while (!q.empty()) {
        // for (auto it = q.begin(); it != q.end(); ++it) cout << it->lifts << "
        // "; cout << endl;
        node now = *q.begin();
        q.erase(q.begin());
        if (now.person_left == 0) {
            printf("%d\n", now.lifts + (now.current_load > 0));
            break;
        }
        bool not_found = true;
        for (int i = now.last_pick + 1, k = 1 << (now.last_pick + 1); i < n;
             k <<= 1, i++) {
            if (w[i] > x - now.current_load) break;
            if (now.picked & k) continue;
            q.insert({now.person_left - 1, now.lifts, now.picked | k,
                      now.current_load + w[i], i});
            not_found = false;
        }
        if (not_found)
            for (int i = 1, k = 2; i < n; k <<= 1, i++) {
                if (now.picked & k) continue;
                // if (w[i] <= x-now.current_load) break;
                if (w[i] > x - now.current_load)
                    q.insert({now.person_left - 1, now.lifts + 1,
                              now.picked | k, w[i], i});
                break;
            }
    }
}
