#include <bits/stdc++.h>
using namespace std;
int r, v, d[100005], c[100005], q[100005], head = 1, tail, n, m;
int f[100005][30], fc[100005][30];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", d + i, c + i);
        while (head <= tail and d[q[tail]] < d[i]) {
            f[q[tail]][0]  = i;
            fc[q[tail]][0] = c[i];
            tail--;
        }
        q[++tail] = i;
    }
    for (int j = 1, k = 1; k < n; j++, k <<= 1) {
        for (int i = 1; i + k <= n; i++) {
            f[i][j]  = f[f[i][j - 1]][j - 1];
            fc[i][j] = fc[i][j - 1] + fc[f[i][j - 1]][j - 1];
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < 5; j++) cout << f[i][j] << " ";
    //     cout << endl;
    // }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &r, &v);
        // cout << r << " " << v << " ";
        if (v <= c[r]) {
            printf("%d\n", r);
            continue;
        }
        int p = r;
        v -= c[r];
        while (v > 0) {
            bool found  = false;
            int found_j = -1;
            for (int j = 0; j < 30; j++) {
                if (f[p][j]) found_j = j;
                if (fc[p][j] >= v and f[p][j] > 0) {
                    found   = true;
                    found_j = j;
                    break;
                }
            }
            // cout << "Found " << found << "p" << p << "found_j" << found_j
            //      << " v" << v << "c" << c[p] << " ";
            // for (int j = 0; fc[p][j] > 0; j++) {
            //     cout << f[p][j] << ">" << fc[p][j] << " ";
            // }
            // cout << endl;
            if (!found) {
                if (found_j < 0) {
                    puts("0");
                    break;
                } else {
                    v -= fc[p][found_j];
                    p = f[p][found_j];
                }
            } else if (fc[p][found_j] == v or found_j == 0) {
                printf("%d\n", f[p][found_j]);
                break;
            } else {
                v -= fc[p][found_j - 1];
                p = f[p][found_j - 1];
            }
        }
    }
}
