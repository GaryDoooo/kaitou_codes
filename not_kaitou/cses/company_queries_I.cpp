#include <stdio.h>
#define N 212345
#define LOG2N 20
int q, n, x, k;
int p[N][LOG2N];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        p[i][0] = x;
    }

    for (k = 1, x = 1; k <= n; k *= 2, x++)
        for (int i = 2; i <= n; i++) p[i][x] = p[p[i][x - 1]][x - 1];

    while (q--) {
        scanf("%d %d", &x, &k);
        int i = 0;
        while (k > 0) {
            if (k & 1) x = p[x][i];
            i++;
            k /= 2;
        }
        if (x == 0)
            puts("-1");
        else
            printf("%d\n", x);
    }
}

