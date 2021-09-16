#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, maxw;
    cin >> n >> maxw;
    int w[n], v[n];
    int b[maxw + 1];
    memset(	b, 0, sizeof(b));
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = maxw; j >= w[i]; j--) {
            b[j] = max(b[j], b[j - w[i]] + v[i]);
        }
    }
    cout << *max_element(b, b + maxw + 1);
}