#include <bits/stdc++.h>
using namespace std;
int n, h, MOD = 1e9 + 7, full_mask;  //, good[1030][1030];
int last_row[1030], this_row[1030];
vector<int> nxt[1030], options;
// set<int> options_set;
void make_options_dfs(int rest, int res) {
    if (rest <= 0) {
        options.push_back(res & full_mask);
        return;
    }
    make_options_dfs(rest - 1, res << 1 | 1);
    if (rest > 1) make_options_dfs(rest - 2, res << 2);
}

// void print_bits(int x) {
//     cout << x << ": " << '\t';
//     for (int i = 31; i >= 0; i--) {
//         cout << ((x >> i) & 1);
//     }
//     cout << endl;
// }

int main() {
    cin >> n >> h;
    if (h == 1) {
        cout << !(n & 1);
        return 0;
    }
    full_mask = (1 << n) - 1;
    make_options_dfs(n, 0);
    int mask_count = 1 << n;
    // for (int i : options) print_bits(i);
    // cout << options.size() << endl;
    for (int i = 0; i < mask_count; i++)
        for (int j : options) {
            bool ok = true;
            int ii = i, jj = j;
            for (int k = 0; k < n; k++) {
                if (ii & 1 and !(jj & 1)) {
                    ok = false;
                    break;
                }
                ii >>= 1;
                jj >>= 1;
            }
            if (ok) {
                // good[i][j]=1;
                nxt[i].push_back(j);
                // cout << "i= ";
                // print_bits(i);
                // cout << "j= ";
                // print_bits(j);
            }
        }
    for (int i : options) last_row[i] = 1;
    for (int y = 2; y < h; y++) {
        memset(this_row, 0, sizeof(this_row));
        for (int i = 0; i < mask_count; i++) {
            if (last_row[i] == 0) continue;
            for (int j : nxt[i]) {
                int new_mask       = (~i) & j;
                this_row[new_mask] = (this_row[new_mask] + last_row[i]) % MOD;
            }
        }
        swap(last_row, this_row);
    }
    int res = 0;
    for (int i : options) res = (res + last_row[i]) % MOD;
    cout << res << endl;
}
