#include <bits/stdc++.h>
using namespace std;
struct node {
    int rides, picked, residue;
    friend bool operator<(const node& a, const node& b) {
        return a.rides > b.rides;
    }
};
priority_queue<node> q;
map<int, int> m;
int n, x, w[22];  //, res = 1e9;
vector<int> s[22];

bool pick_chain(int sum, int* picked) {
    if (sum == 0) return true;
    for (int i = n - 1, k = 1 << (n - 1); i >= 0; k >>= 1, i--) {
        if ((~(*picked)) & k and (m[sum] & k)) {
            // cout << k << " " << i << endl;
            *picked |= k;
            if (pick_chain(sum - w[i], picked)) return true;
            *picked ^= k;
        }
    }
    return false;
}

// void dfs(int person_idx, int cart_on_loading, int residue) {}

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
        for (auto& p : s[j]) m[p] |= 1 << j;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << w[i] << ": ";
    //     for (auto it : s[i]) cout << it << " ";
    //     cout << m[w[i]] << endl;
    // }
    // dfs(n - 1, 0, sum);
    // printf("%d\n", res);
    // q.push({2, 0, 0});
    q.push({1, 0, sum});
    // q.push({3, 0, 0});
    // cout << q.top().rides << endl;
    // return 0;
    while (!q.empty()) {
        // cout << q.top().rides << endl;
        node now = q.top();
        q.pop();
        int cart_on_loading = now.rides, residue = now.residue,
            picked = now.picked;
        // if (cart_on_loading + residue / x + (residue % x > 0) >= res)
        //     continue;
        // else {
        int person_idx, k = 1 << n - 1;
        for (int i = n - 1; i >= 0; k >>= 1, i--)
            if ((~picked) & k) {
                person_idx = i;
                break;
            }
        // cout π<< person_idx << endl;
        // cout << k << endl;
        picked |= k;  // 1 << person_idx;
        // cout << picked << endl;
        for (int i = s[person_idx].size() - 1, j = 0; i >= 0 and j < 5; i--) {
            int sum    = s[person_idx][i];
            int backup = picked;
            // memcpy(backup, picked, sizeof(backup));
            if (pick_chain(sum - w[person_idx], &picked)) {
                if (residue == sum) {
                    printf("%d\n", cart_on_loading);
                    return 0;
                }
                // cout << picked << endl;
                j++;
                q.push({cart_on_loading + 1, picked, residue - sum});
            }
            // dfs(person_idx - 1, cart_on_loading + 1, residue - sum);
            picked = backup;
            // memcpy(picked, backup, sizeof(picked));
            // }
        }
    }
}
