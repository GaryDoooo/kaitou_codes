#include <bits/stdc++.h>
using namespace std;
int q[112345];
int n, m, a, b, head = 1, tail, d[112345];
vector<int> e[112345];
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (d[i]) continue;
        head = 1, tail = 1;
        q[++tail] = i;
        d[i]      = 1;
        while (head <= tail) {
            int now   = q[head++];
            int depth = d[now] + 1;
            for (int i : e[now]) {
                if (d[i]) {
                    if ((d[i] & 1) ^ (depth & 1)) {
                        puts("IMPOSSIBLE");
                        return 0;
                    }
                } else {
                    q[++tail] = i;
                    d[i]      = depth;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", 2 - (d[i] & 1));
}
