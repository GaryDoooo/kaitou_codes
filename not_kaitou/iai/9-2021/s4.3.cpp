#include <bits/stdc++.h>
using namespace std;
struct number {
    int two, five;
};
int count_factor(long long a, int b) {
    int res = 0;
    while (a % b == 0) res++, a /= b;
    return res;
}
int main() {
    int n, k, res = 0, left_point, total_five = 0;
    long long a_in;
    cin >> n >> k;
    number a[n];
    for (int i = 0; i < n; i++) {
        cin >> a_in;
        total_five += (a[i].five = count_factor(a_in, 5));
        a[i].two = count_factor(a_in, 2);
    }
    int v[k + 1][total_five + 1];
    memset(v, 255, sizeof(v));
    v[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = total_five; j >= 0; j--) {
            if (0 > (left_point = j - a[i].five)) break;
            for (int l = min(i, k - 1); l >= 0; l--)
                if (v[l][left_point] >= 0)
                    v[l + 1][j] = max(v[l][left_point] + a[i].two, v[l + 1][j]);
        }
    for (int i = 0; i <= total_five; i++) res = max(res, min(i, v[k][i]));
    cout << res;
}

