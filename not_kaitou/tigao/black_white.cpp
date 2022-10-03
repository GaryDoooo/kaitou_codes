#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int w[n], b[n], res = 1e9;
    for (int i = 0; i < n; i++) cin >> w[i] >> b[i];
    for (int i = 0; i < (1 << n); i++) {
        int index = 0, t = i, color[n];
        for (int j = 0; j < n; j++) {
            color[j] = (t & 1);
            t        = t >> 1;
        }
        int total_white = accumulate(color, color + n, 0);
        bool fit        = true;
        for (int j = 0; j < n; j++) {
            if (color[j]) {
                if (total_white - 1 != w[j] or n - total_white != b[j])
                    fit = false;
            } else {
                if (total_white == w[j] and n - total_white - 1 == b[j])
                    fit = false;
            }
        }
        if (fit) {
            int result = 0;
            for (int j = 0; j < n; j++) {
                if (color[j]) {
                    result *= 10;
                    result += j + 1;
                }
            }
            res = min(res, result);
        }
    }
    if (res == 1e9)
        cout << "NoSolution";
    else
        cout << res;
}

