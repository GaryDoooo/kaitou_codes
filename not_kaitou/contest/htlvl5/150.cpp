#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int p[1000], n, ps[1000];
int main() {
    memset(p, 1, sizeof(p));
    for (int i = 3; i <= sqrt(1000); i += 2) {
        if (p[i])
            for (int j = i * i; j <= sqrt(100000); j += i) p[j] = 0;
    }
    ps[0]   = 2;
    int idx = 0, cnt = 0;
    cin >> n;
    for (int i = 3; i <= sqrt(n); i++)
        if (p[i]) ps[++idx] = i;
    for (int i = 6; i <= n; i++) {
        int sum = 1, t = i;
        double sq = sqrt(i);
        for (int j = 0; j <= idx; j++) {
            if (ps[j] > sq) break;
            if ((double)ps[j] == sq) {
                sum += ps[j];
                break;
            }
            while (t % ps[j] == 0) {
                int ys1 = t / ps[j];
                int ys2 = i / ys1;
                sum += ys1 + ys2;
                t /= ps[j];
            }
            // if (t == 1) break;
        }
        cnt += (sum == i);
        // cout << i << " " << sum << endl;
    }
    cout << cnt << endl;
}

