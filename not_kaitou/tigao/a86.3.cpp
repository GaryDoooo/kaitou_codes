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
void bfs(int enter_point) {
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
                    puts("-1");
                    exit(0);
                }
                if (!in_q[i]) {
                    q.push(i);
                    in_q[i] = 1;
                }
            }
        }
    }
}

int main() {
    memset(a, 127, sizeof(a));
    scanf("%d%d%d", &n, &m, &ss);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &aa, &b, &c);
        a[aa][b] = min(a[aa][b], c);
        insert(s[aa], b);
    }
    bfs(ss);
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) bfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (i == ss)
            puts("0");
        else if (a[ss][i] > 2e9)
            puts("NoPath");
        else
            printf("%d\n", a[ss][i]);
    }
}
