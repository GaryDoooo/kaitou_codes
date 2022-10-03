#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], cnt[1005], s[1005][1005], in_q[1005];
//, f[1005][1005], changed_to[1005][1005],changed_to2[1005][1005];
int n, m, ss, aa, b, c, changed, last_changed, n1, n2, n3;
// int c1[1005], c2[1005];  // from[1000005], to[1000005];
void insert(int *a, int index) {
    if (a[index] == 0) {
        a[index] = (a[0] == 0 ? -1 : a[0]);
        a[0]     = index;
    }
}
bool bfs(int enter_point) {
    queue<int> q;
    memset(in_q, 0, sizeof(in_q));
    for (int i = s[enter_point][0]; i > 0; i = s[enter_point][i]) {
        q.push(i);
        cnt[i]++;
        in_q[i] = 1;
    }
    a[enter_point][enter_point] = 0;
    cnt[enter_point]++;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        in_q[now] = 0;
        for (int i = s[now][0]; i > 0; i = s[now][i]) {
            if (a[enter_point][now] + a[now][i] < a[enter_point][i]) {
                a[enter_point][i] = a[enter_point][now] + a[now][i];
                // insert(s[enter_point],i);
                cnt[i]++;
                if (cnt[i] > n or i == enter_point) {
                    // puts("NO");
                    // exit(0);
                    return false;
                }
                if (!in_q[i]) {
                    q.push(i);
                    in_q[i] = 1;
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(a, 127, sizeof(a));
        memset(cnt, 0, sizeof(cnt));
        memset(s, 0, sizeof(s));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &aa, &b, &c);
            a[aa][b] = min(a[aa][b], c);
            insert(s[aa], b);
            if (c > 0) {
                swap(aa, b);
                a[aa][b] = min(a[aa][b], c);
                insert(s[aa], b);
            }
        }
        bool res = true;
        // bfs(ss);
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                bool temp_res = bfs(i);
                if (!temp_res) {
                    res = false;
                    break;
                }
            }
        }
        cout << (!res ? "YES" : "NO") << endl;
        // for (int i = 1; i <= n; i++) {
        //     if (i == ss)
        //         puts("0");
        //     else if (a[ss][i] > 2e9)
        //         puts("NoPath");
        //     else
        //         printf("%d\n", a[ss][i]);
        // }
    }
}
