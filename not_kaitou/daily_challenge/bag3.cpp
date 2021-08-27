#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int maxw = read(), n = read();
    register int w, v;
    int maxv[maxw + 1];
    memset(maxv, 0, sizeof(maxv));
    for (int i = 0; i < n; i++) {
        // w[i] = read(), v[i] = read();
        w = read(), v = read();
        for (register int j = maxw; j >= w; j--) {
            maxv[j] = max(
                          maxv[j], maxv[j - w] + v);
        }
    }
    cout << *max_element(maxv, maxv + maxw + 1);
}