#include <bits/stdc++.h>
using namespace std;
int n, nxt[33000], cnt = 1, pre[33000];
int another_father[33000], n0, n1;

int get_another_father(int i) { return (i / 2) | n1; }

void print() {
    for (int i = 0; i < n; i++) putchar('0');
    for (int i = 1; i; i = nxt[i]) printf("%d", i & 1);
    putchar('\n');
    exit(0);
}

int same_side(int branch, int leaf) {
    int another_branch = branch ^ 1;
    for (register int i = leaf; i > 1; i = pre[i] ? pre[i] : i / 2)
        if (i == branch)
            return 1;
        else if (i == another_branch)
            return 0;
    return 0;
}

void dfs(int x) {
    if (++cnt == n0) print();
    if (nxt[x])
        dfs(nxt[x]);
    else if (x < n1)
        for (int i = x * 2; i <= x * 2 + 1; i++) {
            int j    = i ^ 1;
            int j_fa = another_father[j];
            if (nxt[j_fa] or same_side(j, j_fa)) continue;
            nxt[j_fa] = j, nxt[x] = i, pre[j] = j_fa;
            dfs(i);
            nxt[j_fa] = nxt[x] = pre[j] = 0;
        }
    cnt--;
}

int main() {
    scanf("%d", &n);
    n0 = 1 << n;
    n1 = n0 / 2;
    for (int i = 1; i <= n0; i++) another_father[i] = get_another_father(i);
    dfs(1);
}
