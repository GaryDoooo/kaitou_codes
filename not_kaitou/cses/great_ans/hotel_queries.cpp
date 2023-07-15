#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <limits.h>
#include <stdio.h>

#define N 200001

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

static inline void putint(int x) {
    char s[10];
    short i = 0;
    if (x == 0) {
        putchar_unlocked('0');
        return;
    }
    while (x) {
        s[i++] = (x % 10) + '0';
        x /= 10;
    }
    while (i--) {
        putchar_unlocked(s[i]);
    }
}

static inline int max(int a, int b) { return a > b ? a : b; }

void solve() {
    static int x[1 << 20];
    int n = getint(), m = getint();
    int n0 = (1 << ((sizeof(int) * CHAR_BIT) - __builtin_clz(n - 1))) - 1;
// n0 
    // putint(n0);
    // putint(ONE_BASED_INDEX_OF_HIGHEST_SET_BIT(n));

    for (int i = 1; i <= n; i++) {
        x[n0 + i] = getint();
    }

    for (int i = n0; i > 0; i--) {
        x[i] = max(x[i * 2], x[i * 2 + 1]);
    }

    for (int i = 0; i < m; i++) {
        int r = getint();

        if (x[1] < r) {
            putchar_unlocked('0');
        } else {
            int k = 2;
            while (k <= n0) {
                if (x[k] < r) k++;
                k *= 2;
            }
            if (x[k] < r) k++;

            putint(k - n0);
            x[k] -= r;
            k /= 2;
            while (k) {
                x[k] = max(x[k * 2], x[k * 2 + 1]);
                k /= 2;
            }
        }
        putchar_unlocked(' ');
    }

    putchar_unlocked('\n');
}

int main() { solve(); }

