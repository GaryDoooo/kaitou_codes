#include <iostream>
using namespace std;
int n, q, c[1000005], d[1000005], r, v;
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> c[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> r >> v;
        cout << r << " " << v << " ";
        while (r <= n and v > 0) {
            v -= c[r];
            // cout << "row " << r << " c" << c[r] << " left v" << v << endl;
            if (v <= 0 or r == n) break;
            bool found = false;
            for (int j = r + 1; j <= n + 1; j++) {
                if (d[j] > d[r]) {
                    r     = j;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        if (v <= 0) {
            cout << r << endl;
            // cout << v << " " << c[r] << " " << r << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

