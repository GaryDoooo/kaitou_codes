#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <stdio.h>

#define N 1024
#define C 1000000001

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

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

#define E_N(e) ((e)&0xfff)
#define E_B(e) (((e) >> 12) & 0xfff)
#define E_F(e) ((e) >> 24)
#define E_DF(e, df) (e & 0xffffff) | ((E_F(e) + df) << 24)

static void link(short p[], int e[], int *j, int a, int b) {
    e[*j] = p[a] | (b << 12) | ((1 + (a == 1)) << 24);
    p[a]  = (*j)++;
    e[*j] = p[b] | (a << 12) | ((1 - (a == 1)) << 24);
    p[b]  = (*j)++;
}

// Goldberg Tarjan Push Relabel algorithm
void solve() {
    static short p[N], h[N], ca[N];
    static short y[N];  // answer
    static short ex[N];
    static char active[N];
    static int e[N * 6];
    static int q[N];
    int qt = 0, qh = 0;

    static short anl[N],
        ann[N];    // Active node list for each level; next pointer
    int maxh = 1;  // Maximum active node height
    int anc  = 0;  // Active node count

    static short hc[N];  // Number of nodes for each label

    int ss = 0;  // Number of direct source-to-sink connections

    int n = getint(), m = getint();

    int j = 2;
    for (int i = 0; i < m; i++) {
        int a = getint(), b = getint();
        if (a == n || b == 1) {
            continue;
        }
        if (a == 1 && b == n) {
            ss++;
            continue;
        }
        link(p, e, &j, a, b);
        if (a == 1) {
            ex[b]++;
        }
    }

    // Initialise heights
    q[qt++] = n;
    while (qh < qt) {
        int a = q[qh++];
        for (int j = p[a]; j; j = E_N(e[j])) {
            int b = E_B(e[j]);
            if ((j & 1) && !h[b]) {
                h[b] = h[a] + 1;
                hc[h[b]]++;
                q[qt++] = b;
            }
        }
    }

    // Activate preflow
    for (int j = p[1]; j; j = E_N(e[j])) {
        int b = E_B(e[j]);
        if (!active[b]) {
            active[b] = 1;
            anc++;
            ann[b]    = anl[h[b]];  // Insert into active node list
            anl[h[b]] = b;
            maxh      = MAX(maxh, h[b]);
        }
    }

    h[1] = n;

    for (int i = 1; i <= n; i++) {
        ca[i] = p[i];  // Set current arc for each node
    }

    // Main loop
    while (anc) {
        anc--;
        while (!anl[maxh]) {
            maxh--;
        }
        int a     = anl[maxh];  // Highest label selection rule
        anl[maxh] = ann[a];

        active[a] = 0;

        // Discharge
        int j = ca[a];  // Current arc for node a
        while (ex[a] > 0) {
            if (j) {
                int b = E_B(e[j]);
                if (h[a] == h[b] + 1) {  // Is admissiable arc
                    // Push
                    int c =
                        2 - (j & 1);  // Forward/reverse edges have capacity 2/1
                    int f  = E_F(e[j]);
                    int df = MIN(c - f, ex[a]);
                    if (df) {
                        ex[a] -= df;
                        ex[b] += df;
                        e[j]     = E_DF(e[j], df);
                        e[j ^ 1] = E_DF(e[j ^ 1], -df);

                        if (!active[b] && b != 1 &&
                            b != n) {  // Sink and source never become active
                            active[b] = 1;
                            // Insert into active node list
                            ann[b]    = anl[h[b]];
                            anl[h[b]] = b;
                            anc++;
                            maxh = MAX(maxh, h[b]);
                        }
                    }
                }

                j = E_N(e[j]);
            } else {
                // Relabel
                int minh = C;
                for (j = p[a]; j; j = E_N(e[j])) {
                    int c =
                        2 - (j & 1);  // Forward/reverse edges have capacity 2/1
                    int f = E_F(e[j]);
                    if (f < c) {
                        minh = MIN(minh, h[E_B(e[j])]);
                    }
                }

                int oldh = h[a];
                int newh = minh + 1;
                h[a]     = newh;
                hc[newh]++;
                hc[oldh]--;

                if (hc[oldh] == 0) {
                    // Gap heuristic: relabel any node with label > oldh as n +
                    // 1 This could be made more efficient e.g. by maintaining a
                    // linked list of nodes with labels <
                    n + 1 for (int i = 2; i < n; i++) {
                        if (h[i] > oldh && h[i] < n + 1) {
                            hc[h[i]]--;
                            h[i] = n + 1;
                            maxh = n + 1;
                        }
                    }
                }

                j = p[a];
            }
        }
        ca[a] = j;  // Update current arc
    }

    int yn = ex[n];
    putint(yn + ss);
    putchar_unlocked('\n');

    // Output paths
    while (yn--) {
        int t = 0;
        int a = 1;
        while (a != n) {
            int j = ca[a] ? ca[a] : p[a];
            int b = 0;
            while (!b) {
                // printf("j=%d\n", j);
                if ((j & 1) == 0) {
                    int f = E_F(e[j]);
                    if (f == 2) {
                        b = E_B(e[j]);
                    }
                }
                j = E_N(e[j]) ? E_N(e[j]) : p[a];
            }
            ca[a]  = j;
            y[t++] = b;
            a      = b;
        }
        putint(t + 1);
        putchar_unlocked('\n');
        putchar_unlocked('1');
        putchar_unlocked(' ');
        for (int i = 0; i < t; i++) {
            putint(y[i]);
            putchar_unlocked(' ');
        }
        putchar_unlocked('\n');
    }

    while (ss--) {
        putchar_unlocked('2');
        putchar_unlocked('\n');
        putchar_unlocked('1');
        putchar_unlocked(' ');
        putint(n);
        putchar_unlocked('\n');
    }
}

int main() { solve(); }
