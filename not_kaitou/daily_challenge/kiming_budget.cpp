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
    int maxw = read() / 10, n = read();
    int w[n + 1], v[n + 1], father;
    int bestv[maxw + 1];
    memset(bestv, 0, sizeof(bestv));
    for (int i = 1; i <= n; i++) {
        w[i] = read() / 10, v[i] = read() * w[i], father = read();
        if (father) {
            for (int j = maxw; j >= w[i] + w[father]; j--) {
                // if (j - w[i] < w[father]) break;
                if (bestv[j - w[i]] != bestv[j - w[i] - w[father]] + v[father]) continue;
                bestv[j] = max(bestv[j], bestv[j - w[i]] + v[i]);
            }
        } else {
            for (int j = maxw; j >= w[i]; j--)
                bestv[j] = max(bestv[j], bestv[j - w[i]] + v[i]);
        }
    }
    cout << *max_element(bestv, bestv + maxw + 1) * 10;
}