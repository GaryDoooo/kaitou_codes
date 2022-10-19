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
     int p[N], e[M * 2];  // edge pointers
     int v[N];            // visited index
     int s[N];            // stack
    int sp = 0;

    int n = getint(), m = getint();

    // Create edge pointers
    for (int i = 0, j = 1; i < m; i++) {
        int a = getint(), b = getint();

        e[j]     = b;
        e[j + 1] = p[a];
        p[a]     = j;

        j += 2;
    }

    for (int i = 1; i < n; i++) {
        sp = 0;

        s[++sp] = i;
        s[++sp] = p[i];
        v[i]    = 1;

        while (sp) {
            int j = s[sp];
            if (j && v[e[j]] != -1) {
                int b = e[j];
                if (v[b]) {
                    // cycle found
                    putint(2 + (sp - v[b]) / 2);
                    putchar_unlocked('\n');
                    for (int k = v[b]; k < sp; k += 2) {
                        putint(s[k]);
                        putchar_unlocked(' ');
                    }
                    putint(b);
                    putchar_unlocked('\n');
                    return 0;
                } else {
                    s[sp]   = e[j + 1];
                    s[++sp] = b;
                    v[b]    = sp;
                    s[++sp] = p[e[j]];
                }
            } else {
                v[s[sp - 1]] = -1;  // Mark as lost
                sp -= 2;
            }
        }
    }

    puts("IMPOSSIBLE");
}

