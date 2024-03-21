#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int em[312345], om[312345], emin[312345], omin[312345];
int res[312345], res_cnt;

int dfs(int x, int left) {
    if (x > m) return 1;
    res[x] = 0;
    if (om[x] == 0) {
        if (dfs(x + 1, left + emin[x])) return 1;
    } else if (om[x] < left) {
        if (dfs(x + 1, left - om[x])) return 1;
    }
    res[x] = 1;
    if (em[x] == 0) {
        if (dfs(x + 1, left + omin[x])) return 1;
    } else if (em[x] < left) {
        if (dfs(x + 1, left - em[x])) return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        memset(om, 0, sizeof(om));
        memset(em, 0, sizeof(em));
        memset(omin, 127, sizeof(omin));
        memset(emin, 127, sizeof(emin));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                int a;
                scanf("%d", &a);
                if (a & 1) {
                    om[i]   = max(om[i], a);
                    omin[i] = min(omin[i], a);
                } else {
                    em[i]   = max(em[i], a);
                    emin[i] = min(emin[i], a);
                }
            }
            if (emin[i] > 1e9) emin[i] = 0;
            if (omin[i] > 1e9) omin[i] = 0;
        }
        if (dfs(1, n)) {
            for (int i = 1; i < m; i++) {
                if (res[i])
                    printf("ODD ");
                else
                    printf("EVEN ");
            }
            if (res[m])
                puts("ODD");
            else
                puts("EVEN");
        } else
            puts("-1");
    }
}

