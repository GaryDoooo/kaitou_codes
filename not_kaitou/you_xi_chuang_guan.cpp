#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    int a[100010], b, s = 0, ai_max = 0;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        if (s <= t) {
            a[i] = s;
            ai_max = i;
        }
    }
    s = 0;
    int max_res = ai_max, ai = ai_max;
    for (int i = 0; i < n; i++) {
        cin >> b;
        s += b;
        while (s + a[ai] > t and ai > 0)
            ai--;
        if (s + a[ai] > t) break;
        if (i + ai + 1 > max_res) max_res = ai + i + 1;
    }
    cout << max_res << endl;
    return 0;
}
