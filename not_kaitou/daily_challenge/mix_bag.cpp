#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int n = read(), maxv = read(), v, w, amt, vi[10], wi[10];
    int bestv[maxv + 1];
    memset(bestv, 0, sizeof(bestv));
    for (int i = 0; i < n; i++) {
        w = read(); v = read(); amt = abs(read());
        if (amt > 0) {
            int index = 0, base = 1, s = amt;
            for (; s > base; base = base << 1) {
                vi[index] = base * v;
                wi[index++] = base * w;
                s -= base;
            }
            vi[index] = s * v;
            wi[index++] = s * w;
            for (int j = 0; j < index; j++) {
                for (int k = maxv; k >= wi[j]; k--) bestv[k] = max(bestv[k], bestv[k - wi[j]] + vi[j]);
            }
        } else {
            for (int k = w; k <= maxv; k++) bestv[k] = max(bestv[k], bestv[k - w] + v);
        }
    }
    cout << *max_element(bestv, bestv + maxv + 1) << endl;
}