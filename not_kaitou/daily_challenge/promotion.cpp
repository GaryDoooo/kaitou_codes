#include <bits/stdc++.h>
using namespace std;

int main() {
    int total_w, total_v, n;
    cin >> total_w >> total_v >> n;
    int w[n], v[n], p[n], max_p = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i] >> p[i];
    }
    unsigned int res;
    for (unsigned int i = 0; i < 1 << n; i++) {
        unsigned int ii = i, index = 0;
        int current_w = 0, current_v = 0, current_p = 0;
        while (ii > 0) {
            if (ii % 2 == 1) {
                current_w += w[index];
                current_v += v[index];
                current_p += p[index];
            }
            index++;
            ii = ii >> 1;
        }
        if (current_w <= total_w and current_v <= total_v) {
            if (current_p > max_p) {
                max_p = current_p;
                res = i;
            }
        }
    }
    cout << max_p << endl;
    for (int i = 0; i < n; i++) {
        if (res % 2 == 1) cout << i + 1 << " ";
        res = res >> 1;
    }
    return 0;
}