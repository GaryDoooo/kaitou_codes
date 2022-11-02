// 如果从1号点可以到任何一个点，并且从任何一个点可以到1号点
// 那么这个图就满足题目要求，任何一个点之间都可以相连。 反之亦然。
// 所以这两个命题是等效的。
//
// 拿所有的入边做一遍广搜遍历，再用出边做一遍即可。

#include <stdio.h>

#define N 100001
#define M 200001

static inline int getint() {
    int x, y;
    while ((x = getchar_unlocked()) < '0') {
    }
    x -= '0';
    while ((y = getchar_unlocked()) >= '0') {
        x = x * 10 + y - '0';
    }
    return x;
}

int main() {
    static int p[2][N], e[2][M * 2];
    static char v[2][N];
    static int q[M];

    int n = getint(), m = getint();

    for (int i = 0, j = 1; i < m; i++, j += 2) {
        int a = getint(), b = getint();
        e[0][j]     = b;
        e[0][j + 1] = p[0][a];
        p[0][a]     = j;

        e[1][j]     = a;
        e[1][j + 1] = p[1][b];
        p[1][b]     = j;
    }

    for (int i = 0; i < 2; i++) {
        int qt = 0, qh = 0;
        q[qh++] = 1;
        while (qt < qh) {
            int a = q[qt++];
            if (!v[i][a]) {
                v[i][a] = 1;
                for (int j = p[i][a]; j; j = e[i][j + 1]) {
                    int b = e[i][j];
                    if (!v[i][b]) {
                        q[qh++] = b;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!v[0][i]) {
            puts("NO");
            printf("1 %d\n", i);
            return 0;
        }
        if (!v[1][i]) {
            puts("NO");
            printf("%d 1\n", i);
            return 0;
        }
    }

    puts("YES");
}
