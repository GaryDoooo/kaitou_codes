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
struct item {
    int w , v , s1, s2;
};
int main() {
    int maxw, n, father;
    maxw = read() / 10, n = read();
    item itm[n + 1];
    memset(itm, 0, sizeof(itm));
    int b[maxw + 1];
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
        itm[i].w = read() / 10; itm[i].v = read() * itm[i].w;
        father = read();
        if (father) {
            itm[i].s1 = -1;
            if (itm[father].s1)
                itm[father].s2 = i;
            else
                itm[father].s1 = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (itm[i].s1 == -1) continue;
        for (int j = maxw; j >= itm[i].w; j--) {
            b[j] = max(b[j], b[j - itm[i].w] + itm[i].v);
            if (j - itm[i].w - itm[itm[i].s1].w >= 0) b[j] = max(b[j],
                        b[j - itm[i].w - itm[itm[i].s1].w] + itm[i].v + itm[itm[i].s1].v);
            if (j - itm[i].w - itm[itm[i].s2].w >= 0) b[j] = max(b[j],
                        b[j - itm[i].w - itm[itm[i].s2].w] + itm[i].v + itm[itm[i].s2].v);
            if (j - itm[i].w - itm[itm[i].s2].w - itm[itm[i].s1].w >= 0)
                b[j] = max(b[j],
                           b[j - itm[i].w - itm[itm[i].s1].w - itm[itm[i].s2].w]
                           + itm[i].v + itm[itm[i].s2].v + itm[itm[i].s1].v);
        }
    }
    cout << *max_element(b, b + maxw + 1) * 10;
}