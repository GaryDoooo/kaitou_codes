#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, m;
vector<int> e_in[22], e_out[22];
unordered_map<int, unordered_map<int, unsigned int>> a, nxt;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e_out[a].push_back(b);
        e_in[b].push_back(a);
    }
    a[1][0] = 1;
    for (int i = 0; i < 9; i++) {
        nxt.clear();
        for (auto node : a) {
            int from                            = node.first;
            unordered_map<int, unsigned int> &i = node.second;
            for (auto j : i) {
                int code           = j.first;
                unsigned int count = j.second;
                for (int to : e_out[from]) {
                    if (code & (1 << (to - 2))) continue;
                    int new_code = code | (1 << (to - 2));
                    nxt[to][new_code] += count;
                    nxt[to][new_code] %= MOD;
                }
            }
        }
        swap(nxt, a);
    }
    unsigned int res = 0;
    int code         = (1 << (n - 2)) - 1;
    for (int from : e_in[n]) res = (res + a[from][code]) % MOD;
    cout << res;
}

