#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x  = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
struct en {
    int v, i;
};
bool cmp(const en& a, const en& b) { return a.v < b.v; }
int main() {
    int n = read();
    en a[n];
    for (register int i = 0; i < n; i++) a[i].v = read(), a[i].i = i;
    sort(a, a + n, cmp);
    int odd_cnt = (n + 1) >> 1;
    int cnt[odd_cnt], res[odd_cnt];
    memset(cnt, 0, sizeof(cnt));
    for (register int i = 0; i < n; i++) {
        for (register int j = (a[i].i + 1) / 2; j < odd_cnt; j++) {
            if (cnt[j] < 0) continue;
            if (++cnt[j] == j + 1) cnt[j] = -1, res[j] = a[i].v;
        }
    }
    for (int i = 0; i < odd_cnt; i++) printf("%d\n", res[i]);
    // for (int i = 0; i < n; i++) printf("%d %d\n", a[i].v, a[i].i);
}

