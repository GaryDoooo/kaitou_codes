#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i] ;
    int b[2 * n + 5], p[2 * n + 5];
    memset(b, 0, sizeof(b));
    memset(p, 0, sizeof(p));
    b[0] = -2; b[1] = -1;
    for (int i = 0; i < n; i++) b[i * 2 + 2] = a[i], b[i * 2 + 3] = -1;
    b[n * 2 + 2] = -3;
    int c = 0, r = 0;
    for (int i = 1; i < n * 2 + 1; i++) {
        int i_mirror = 2 * c - i;
        if (i < r) {
            p[i] = min(r - i, p[i_mirror]);
        } else {
            p[i] = 0;
        }
        while (b[i + p[i] + 1] == b[i - p[i] - 1]) p[i]++;
        if (i + p[i] > r) {
            c = i; r = i + p[i];
        }
    }
    cout << *max_element(p, p + n * 2 + 2);
}
//  https://www.zhihu.com/question/37289584