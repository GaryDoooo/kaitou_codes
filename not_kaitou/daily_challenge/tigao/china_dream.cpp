#include<bits/stdc++.h>
using namespace std;
int n, k, coin[8], res = 0;
void dfs(int index, int amount) {
    if (amount > n) return;
    if (amount == n) { res++; return; }
    if (index >= k) return;
    for (int i = 0; i <= (n - amount) / coin[index]; i++) {
        dfs(index + 1, amount + i * coin[index]);
    }
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> coin[i];
    sort(coin, coin + k);
    dfs(0, 0);
    cout << res;
}