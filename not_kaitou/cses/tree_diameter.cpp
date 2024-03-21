#include <stdio.h>
int n, res_i, res_d;
int e[412345], h[212345], nxt[412345];

void dfs(int x, int fa, int depth) {
    // printf("x=%d,fa=%d,d=%d\n", x, fa, depth);
    if (depth > res_d) {
        res_d = depth;
        res_i = x;
    }
    for (int i = h[x]; i; i = nxt[i]) {
        if (e[i] == fa) continue;
        dfs(e[i], x, depth + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b, c = i << 1;
        scanf("%d %d", &a, &b);
        e[c]   = b;
        nxt[c] = h[a];
        h[a]   = c++;
        e[c]   = a;
        nxt[c] = h[b];
        h[b]   = c;
    }
    dfs(1, 0, 0);
    dfs(res_i, 0, 0);
    printf("%d", res_d);
}

