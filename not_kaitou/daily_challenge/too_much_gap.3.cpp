#include <bits/stdc++.h>
#define INF 2123456789
using namespace std;
int main() {
    int n, k, v[500005];
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    long long res = 0;
    v[n] = INF;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);
    int right_pointer = upper_bound(v, v + n, v[0] + k) - v - 1;
    for (int i = 0; i < n; i++) {
        while (v[right_pointer] < v[i] + k) right_pointer++;
        if (right_pointer == n)break;
        res += n - right_pointer;
    }
    cout << res << endl;
    return 0;
}
