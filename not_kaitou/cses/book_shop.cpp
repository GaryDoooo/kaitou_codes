#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, x, w[1005], v[1005], f[112345];
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    memset(f, 128, sizeof(f));
    f[0]     = 0;
    int head = 0;
    for (int i = 0; i < n; i++) {
        for (int j = head; j >= 0; j--)
            f[j + w[i]] = max(f[j + w[i]], f[j] + v[i]);
        head = min(x, head + w[i]);
    }
    cout << *max_element(f, f + x + 1) << endl;
}
