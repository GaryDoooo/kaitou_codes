#include <stdio.h>

#define N 200000
#define S 19
#define HS (1 << S)

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

int main() {
    // Zero is initialized for every named variable with static
    static int x[N], a[N], b[N];  // input
    static int p[N], e[N * 2];  // linked list of ranges ending at each position
    static int y[N];            // result
    static int ht[HS], bit[N];  // hash table and binary indexed tree
    int n = getint(), q = getint();

    for (int i = 1; i <= n; i++) {
        x[i] = getint();
    }

    for (int j = 1; j <= q; j++) {
        a[j] = getint(), b[j] = getint();

        e[j]    = p[b[j]];
        p[b[j]] = j;
    }

    int d = 0;  // total number of duplicate values
    for (int i = 1; i <= n; i++) {
        // Query and update last position of x[i]
        unsigned int h = ((x[i] * 0x9e3779b1) >> (33 - S)) << 1;
        int pxi        = 0;
        while (1) {
            if (ht[h] == x[i]) {
                pxi       = ht[h + 1];
                ht[h + 1] = i;
                break;
            } else if (ht[h] == 0) {
                ht[h]     = x[i];
                ht[h + 1] = i;
                break;
            }
            h = (h + 2) % HS;
        }


        // Update bit
        if (pxi) {
            d++;
            while (pxi <= n) {
                bit[pxi]++;
                pxi = (pxi | (pxi - 1)) + 1;
            }
        }

        // Process ranges ending at this point
        for (int j = p[i]; j; j = e[j]) {
            // Query bit
            int aj = a[j] - 1, v = i - a[j] + 1 - d;
            while (aj) {
                v += bit[aj];
                aj &= (aj - 1);
            }
            y[j] = v;
        }
    }

    for (int j = 1; j <= q; j++) {
        putint(y[j]);
        putchar_unlocked('\n');
    }
}
