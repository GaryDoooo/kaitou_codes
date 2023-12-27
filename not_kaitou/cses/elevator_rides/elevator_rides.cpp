#include <bits/stdc++.h>
using namespace std;
int n, x, w[30], picked[30], res = 1e9;
bool dfs(int person_done, int current_w, int ride_cnt, int last_idx) {
    // cout << person_done << " " << ride_cnt << " " << last_idx << endl;
    if (ride_cnt + (current_w > 0) >= res) return false;
    if (person_done == n) {
        res = min(res, ride_cnt + (current_w > 0));
        // cout << res << endl;
        // exit(0);
        return true;
    }
    bool not_found = 1;
    bool r         = false;
    for (int i = last_idx + 1; i < n; i++) {
        if (!picked[i] and w[i] + current_w <= x) {
            picked[i] = 1;
            not_found = 0;
            r |= dfs(person_done + 1, current_w + w[i], ride_cnt, i);
            picked[i] = 0;
            if (!r) return false;
        }
    }
    if (not_found) {
        for (int i = 1; i < n; i++)
            if (!picked[i]) {
                if (w[i] > x - current_w) {
                    return dfs(person_done, 0, ride_cnt + 1, i - 1);
                    // return true;
                } else
                    return false;
            }
    }
    return r;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);  //, [](int x, int y) { return x > y; });
    picked[0] = 1;
    dfs(1, w[0], 0, 0);
    cout << res << endl;
}

