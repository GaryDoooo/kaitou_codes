#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int n, x, w[22], picked[22], res = 1e9;
vector<int> s[22];

bool pick_chain(int sum) {
    if (sum == 0) return true;
    for (int i = n - 1, k = 1 << (n - 1); i >= 0; k >>= 1, i--) {
        if (picked[i] == 0 and (m[sum] & k)) {
            picked[i] = 1;
            if (pick_chain(sum - w[i])) return true;
            picked[i] = 0;
        }
    }
    return false;
}

void dfs(int person_idx, int cart_on_loading, int residue) {
    if (cart_on_loading + residue / x + (residue % x > 0) >= res)
        return;
    else if (person_idx < 0) {
        res = min(res, cart_on_loading);
        cout << res << endl;
        // exit(0);
    } else if (picked[person_idx]) {
        dfs(person_idx - 1, cart_on_loading, residue);
    } else {
        picked[person_idx] = 1;
        for (int i = s[person_idx].size() - 1; i >= 0; i--) {
            int sum = s[person_idx][i];
            int backup[22];
            memcpy(backup, picked, sizeof(backup));
            if (pick_chain(sum - w[person_idx]))
                dfs(person_idx - 1, cart_on_loading + 1, residue - sum);
            memcpy(picked, backup, sizeof(picked));
        }
        picked[person_idx] = 0;
    }
}

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", w + i);
    m[0] = 1;
    sort(w, w + n);
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += w[j];
        for (auto it = m.begin(); it != m.end(); ++it)
            if (w[j] + it->first > x)
                break;
            else
                s[j].push_back(w[j] + it->first);
        for (auto &p : s[j]) m[p] |= 1 << j;
    }
    for (int i = 0; i < n; i++) {
        cout << w[i] << ": ";
        for (auto it : s[i]) cout << it << " ";
        cout << m[w[i]] << endl;
    }
    dfs(n - 1, 0, sum);
    printf("%d\n", res);
}
