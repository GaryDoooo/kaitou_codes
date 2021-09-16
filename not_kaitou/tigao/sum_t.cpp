#include <bits/stdc++.h>
using namespace std;
int n, a[30], used[30] = {0}, cnt = 0, s;
set<int> printed;
void print_result() {
    int t = 0;
    for (int i = n - 1; i >= 0; i--) {
        t = t << 1;
        t += used[i];
    }
    if (printed.find(t) != printed.end()) return;
    printed.insert(t);
}
void dfs(int index, int sum) {
    if (sum == s) print_result();
    if (index >= n) return;
    used[index] = 1;
    dfs(index + 1, sum + a[index]);
    used[index] = 0;
    dfs(index + 1, sum);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    printed.insert(0);
    dfs(0, 0);
    for (int k : printed) {
        // cout << k << endl;
        if (k == 0) continue;
        int t = k;
        for (int i = 0; i < n; i++) {
            if (t & 1) printf("%d ", a[i]);
            t = t >> 1;
        }
        printf("\n");
    }
    cout << printed.size() - 1;
}
