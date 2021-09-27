#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, n;
    cin >> h >> n;
    int b[h + 1], w[n];
    for (int i = 0; i < n; i++) cin >> w[i];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) {
        for (int j = h; j >= w[i]; j--) {
            b[j] = max(b[j], w[i] + b[j - w[i]]);
        }
    }
    cout << *max_element(b, b + h + 1);
}
