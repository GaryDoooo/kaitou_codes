#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int s[1005][1005], f[1005][1005], changed_to[1005][1005],
    changed_to2[1005][1005];
int n, m, ss, aa, b, c, changed, last_changed, n1, n2, n3;
int c1[1005], c2[1005];  // from[1000005], to[1000005];
void insert(int *a, int index) {
    if (a[index] == 0) {
        a[index] = (a[0] == 0 ? -1 : a[0]);
        a[0]     = index;
    }
}
int main() {
    memset(a, 127, sizeof(a));
    scanf("%d%d%d", &n, &m, &ss);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &aa, &b, &c);
        a[aa][b] = c;
        insert(s[aa], b);
        // insert(f[b], aa);
        // s[aa].insert(b);
        // f[b].insert(aa);
        // c2[aa] = 1;
        insert(changed_to2[aa], b);
        insert(c2, aa);
        // changed_to2[aa].insert(b);
    }
    do {
        changed = 0;
        memset(c1, 0, sizeof(c1));
        // for (int i = 1; i <= n; i++) changed_to[i].clear();
        memset(changed_to, 0, sizeof(changed_to));
        // for (int i = 1; i <= n; i++) {
        // if (c2[i] == 0) continue;
        for (int i = c2[0]; i > 0; i = c2[i]) {
            n1 = i;
            // for (int n2 : changed_to2[n1])
            for (n2 = changed_to2[n1][0]; n2 > 0; n2 = changed_to2[n1][n2])
                // for (int n3 : s[n2]) {
                for (n3 = s[n2][0]; n3 > 0; n3 = s[n2][n3]) {
                    if (a[n1][n2] + a[n2][n3] < a[n1][n3]) {
                        a[n1][n3] = a[n1][n2] + a[n2][n3];
                        if (n1 == n3) {
                            if (a[n1][n3] < 0) {
                                puts("-1");
                                return 0;
                            }
                        } else {
                            insert(s[n1], n3);
                            // insert(f[n3], n1);
                            insert(changed_to[n1], n3);
                            // s[n1].insert(n3);
                            // f[n3].insert(n1);
                            // c1[n1] ;
                            insert(c1, n1);
                            changed = 1;
                            // changed_to[n1].insert(n3);
                        }
                    }
                }
            continue;
            n2 = i;
            // for (int n3 : changed_to2[n1])
            for (n3 = changed_to2[n2][0]; n3 > 0; n3 = changed_to2[n2][n3])
                // for (int n1 : f[n2]) {
                for (n1 = f[n2][0]; n1 > 0; n1 = f[n2][n1]) {
                    if (a[n1][n2] + a[n2][n3] < a[n1][n3]) {
                        a[n1][n3] = a[n1][n2] + a[n2][n3];
                        if (n1 == n3) {
                            if (a[n1][n3] < 0) {
                                puts("-1");
                                return 0;
                            }
                        } else {
                            // s[n1].insert(n3);
                            // f[n3].insert(n1);
                            // c1[n1] =
                            insert(c1, n1);
                            changed = 1;
                            // changed_to[n1].insert(n3);
                            insert(s[n1], n3);
                            insert(f[n3], n1);
                            insert(changed_to[n1], n3);
                        }
                    }
                }
        }
        swap(c1, c2);
        swap(changed_to, changed_to2);
    } while (changed);
    for (int i = 1; i <= n; i++) {
        if (i == ss)
            puts("0");
        else if (a[ss][i] > 2e9)
            puts("NoPath");
        else
            printf("%d\n", a[ss][i]);
    }
}
