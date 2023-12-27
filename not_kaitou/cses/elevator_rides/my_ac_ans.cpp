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
int n, x, w[22];
vector<int> s[22];

bool pick_chain(int sum, int* picked) {
    if (sum == 0) return true;
    for (int i = n - 1, k = 1 << (n - 1); i >= 0; k >>= 1, i--) {
        if ((~(*picked)) & k and (m[sum] & k)) {
            *picked |= k;
            if (pick_chain(sum - w[i], picked)) return true;
            *picked ^= k;
        }
    }
    return false;
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
        for (auto& p : s[j]) m[p] |= 1 << j;
    }
    q.push({1, 0, sum});
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        int cart_on_loading = now.rides, residue = now.residue,
            picked = now.picked;
        int person_idx, k = 1 << n - 1;
        for (int i = n - 1; i >= 0; k >>= 1, i--)
            if ((~picked) & k) {
                person_idx = i;
                break;
            }
        picked |= k;
        for (int i = s[person_idx].size() - 1, cnt = 0; i >= 0 and cnt < 4;
             i--) {
            int sum    = s[person_idx][i];
            int backup = picked;
            if (pick_chain(sum - w[person_idx], &picked)) {
                if (residue == sum) {
                    printf("%d\n", cart_on_loading);
                    return 0;
                }
                cnt++;
                // key is not to push all the sums to the queue.
                // just the max 5 available for each number. Probably smaller
                // also works.
                q.push({cart_on_loading + 1, picked, residue - sum});
            }
            picked = backup;
        }
    }
}
