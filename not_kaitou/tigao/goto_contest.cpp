#include <bits/stdc++.h>
using namespace std;
int m, n, k;
int stack_pointer[20005];
int get_head(int i) {
    while (stack_pointer[i] != i) i = stack_pointer[i];
    return i;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) stack_pointer[i] = i;
    int a, b;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        int a_head            = get_head(a);
        int b_head            = get_head(b);
        stack_pointer[a_head] = b_head;
    }
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) cnt[get_head(i)]++;
    vector<int> w;
    int best[n + 1];
    memset(best, 0, sizeof(best));
    for (int i = 1; i <= n; i++)
        if (cnt[i] > 0) w.push_back(cnt[i]);
    for (auto i : w)
        for (int j = n; j >= i; j--) best[j] = max(best[j], best[j - i] + i);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(best[i] - m) < abs(res - m)) res = best[i];
        if (abs(best[i] - m) == abs(res - m) and best[i] < res) res = best[i];
    }
    cout << res;
}

