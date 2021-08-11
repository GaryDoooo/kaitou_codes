#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000000;
int n;
int cnt, pri[MAXN + 5];
bool vis[MAXN + 5];
int cntNum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i /= 10)
        sum += i % 10;
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 3; i <= n; i += 2) {
        if (!vis[i]) {
            pri[cnt++] = i;
            if (!vis[cntNum(i)])
                cout << i << "\n";
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] >= MAXN)
                break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    return 0;
}