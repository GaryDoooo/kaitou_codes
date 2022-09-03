#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, a[112345], head = 1;
ll res_len, res_a, total_adding;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    // tail=1;
    for (int i = 2; i <= n; i++) {
        // int len=tail-head+1;
        ll new_adding = a[i] - a[i - 1];
        while ((i - head) * new_adding + total_adding > k) {
            total_adding -= a[i - 1] - a[head];
            head++;
        }
        total_adding += (i - head) * new_adding;
        if (i - head > res_len) {
            res_len = i - head;
            res_a   = a[i];
        }
    }
    cout << res_len + 1 << " " << res_a << endl;
}

