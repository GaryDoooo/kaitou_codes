#include <bits/stdc++.h>
using namespace std;
int n, x, w[30], picked[30], res = 1e9;
void dfs(int person_done, int current_w, int ride_cnt) {
    if (ride_cnt + (current_w > 0) >= res) return;
    if (person_done == n) {
        res = min(res, ride_cnt + (current_w > 0));
        return;
    }          
    for (int i = 1; i < n; i++) {
        if (!picked[i] and w[i] + current_w <= x) {
            picked[i] = 1;
            dfs(person_done + 1, current_w + w[i], ride_cnt);
            picked[i] = 0;
        }
    }
    if (current_w > 0) dfs(person_done, 0, ride_cnt + 1);
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    picked[0] = 1;
    dfs(1, w[0], 0);
    cout << res << endl;
}

