#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, m;
vector<int> e_in[22], e_out[22];
unsigned int a[22][262145];  
queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (b != n and b != 1)
            e_out[a].push_back(b);
        else
            e_in[b].push_back(a);
    }
    a[1][0] = 1;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int from = x.first, code = x.second;
        for (int to : e_out[from]) {
            if (code & (1 << (to - 2))) continue;
            int new_code = code | (1 << (to - 2));
            if (a[to][new_code] == 0) {
                q.push(make_pair(to, new_code));
                a[to][new_code] = a[from][code];
            } else {
                a[to][new_code] = (a[to][new_code] + a[from][code]) % MOD;
            }
        }
    }
    unsigned int res = 0;
    int code         = (1 << (n - 2)) - 1;
    for (int from : e_in[n]) res = (res + a[from][code]) % MOD;
    cout << res;
}

