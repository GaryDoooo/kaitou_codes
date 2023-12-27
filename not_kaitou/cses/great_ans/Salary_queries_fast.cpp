   CSES
   doooom — Dark mode Log out

CSES Problem Set

Salary Queries

     * Task
     * Submit
     * Results
     * Statistics
     * Hacking

   Back to hacking
          time          victim  lang  max time
   2023-05-16 14:20:32 ammojamo C++11 0.06 s
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <stdio.h>
#include <stdlib.h>

#define N 200001
#define LX 32
#define B 4
#define BS (1 << B) // node size

static inline int getint() {
    int x, y;
    while((x = getchar_unlocked()) < '0') {}
    x -= '0';
    while((y = getchar_unlocked()) >= '0') { x = x * 10 + y - '0'; }
    return x;
}

static inline void putint(int x) {
    char s[10];
    short i = 0;
    if(x == 0) {
        putchar_unlocked('0');
        return;
    }
    while(x) {
        s[i++] = (x % 10) + '0';
        x /= 10;
    }
    while(i--) {
        putchar_unlocked(s[i]);
    }
}

typedef struct {
        int c[BS], s[BS]; // children, size of children
} t_node;


static void update(t_node *t, int *tn, unsigned int x, int dv) {
        // Insert x into tree
        t_node *cn = t;
        for(int i = LX / B - 1; i >= 0; i--) {
                unsigned int u = x >> (LX - B);
                x <<= B;

                cn->s[u] += dv;

                if(i) {
                        if(!cn->c[u]) {
                                cn->c[u] = (*tn)++;
                        }
                        cn = &t[cn->c[u]];
                }
        }
}

static int query(t_node *t, int j, unsigned int a, unsigned int b) {
        unsigned int au = a >> (LX - B), ar = a % (1 << (LX - B));
        unsigned int bu = b >> (LX - B), br = (b + 1) % (1 << (LX - B));
        t_node cn = t[j];

        if(au == bu) {
                if(cn.c[au]) {
                        return query(t, cn.c[au], a << B, ((b + 1) << B) - 1);
                } else {
                        return cn.s[au];
                }
        } else {
                int v = 0;
                if(ar == 0) {
                        v += cn.s[au];
                } else if(cn.s[au]) {
                        v += query(t, cn.c[au], a << B, 0xffffffffU);
                }
                if(br == 0) {
                        v += cn.s[bu];
                } else if(cn.s[bu]) {
                        v += query(t, cn.c[bu], 0, ((b + 1) << B) - 1);
                }
                for(unsigned int i = au + 1; i < bu; i++) {
                        v += cn.s[i];
                }
                return v;
        }
}

// Solution 1: Bitwise Trie
void solve() {
        static unsigned int x[N];
        static t_node t[N * 10];
        int tn = 1;
        int n = getint(), q = getint();

        for(int i = 1; i <= n; i++) {
                x[i] = getint();
                update(t, &tn, x[i], 1);
        }

        for(int i = 1; i <= q; i++) {
                char type = getchar_unlocked();
                if(type == '!') {
                        int k = getint(), xk = getint();
                        update(t, &tn, x[k], -1);
                        update(t, &tn, xk, 1);
                        x[k] = xk;
                } else {
                        unsigned int a = getint(), b = getint();
                        putint(query(t, 0, a, b));
                        putchar_unlocked('\n');
                }
        }
}

// Solution 2: BIT
void radix_sort(long *x, int n, long *t) {
    static int freq[4][256];
    static long *qp[256];
    long *src, *dst;

    for(int i = 0; i < n; i++) {
        long v = x[i];
        for(int p = 0; p < 4; p++) {
            freq[p][v & 0xff]++;
            v >>= 8;
        }
    }

    for(int p = 0; p < 4; p++) {
        src = (p & 1) ? t : x;
        dst = (p & 1) ? x : t;

        qp[0] = dst;
        for(int i = 1; i < 256; i++) {
            qp[i] = qp[i - 1] + freq[p][i - 1];
        }

        for(int i = 0; i < n; i++) {
            int b = (src[i] >> (p * 8)) & 0xff;
            *qp[b]++ = src[i];
            __builtin_prefetch(qp[b] + 1);
        }
    }
}

// int cmp(const void *a, const void *b) {
//     return *(int *)a - *(int *)b;
// }

void solve2() {
        static int x[N], e[N * 6], t[N * 6], f[N * 3], bit[N * 3];
        int n = getint(), q = getint();
        int j = 0, w = 0;

        for(int i = 1; i <= n; i++) {
                x[i] = getint();
                e[j++] = x[i];
                e[j++] = ('+' << 24) | w++;
        }

        for(int i = 1; i <= q; i++) {
                char type = getchar_unlocked();
                if(type == '!') {
                        int k = getint(), xk = getint();
                        e[j++] = x[k];
                        e[j++] = ('-' << 24) | w++;
                        e[j++] = xk;
                        e[j++] = ('+' << 24) | w++;
                        x[k] = xk;
                } else {
                        int a = getint(), b = getint();
                        e[j++] = a;
                        e[j++] = ('a' << 24) | w++;
                        e[j++] = b;
                        e[j++] = ('b' << 24) | w++;
                }
        }

        // sort events
        radix_sort((long *)e, w, (long *)t);
        // qsort(e, n + q, sizeof(int) * 2, cmp);

        int bn = 0, p = -1;
        for(int i = 0; i < w; i++) {
                int x = e[i * 2], j = e[i * 2 + 1];
                bn += (x != p);
                p = x;
                f[j & 0x00ffffff] = (j & 0xff000000) | bn;
        }

    int v;
        for(int i = 0; i < w; i++) {
                int k = f[i] & 0x00ffffff, t = f[i] >> 24;
                // printf("%c %d\n", t, k);
                if(t == '+' || t == '-') {
                        int d = t == '+' ? 1 : -1;
                        while(k <= bn) { bit[k] += d; k = (k | (k - 1)) + 1; }
                } else if(t == 'a') {
                        v = 0;
                        k--;
                        while(k) { v -= bit[k]; k &= (k - 1); }
                } else {
                        while(k) { v += bit[k]; k &= (k - 1); }
                        putint(v);
                        putchar_unlocked('\n');
                }
        }
}

int main() {
        solve2();
}

   Input as text:

   ________________________________________
   ________________________________________
   ________________________________________
   ________________________________________

   Input as file:                     

   Hack

Range Queries

   ... Forest QueriesHotel QueriesList RemovalsSalary QueriesPrefix Sum QueriesPizzeria QueriesSubarray Sum
   QueriesDistinct Values Queries...
     _______________________________________________________________________________________________________________

Your submissions

   2023-07-16 21:40:14 2023-07-16 21:13:59 2023-07-16 21:12:35 2023-07-16 21:08:48 2023-07-16 20:48:56 2023-07-16
   20:38:10 2023-07-16 08:49:08 2023-07-16 08:41:25 2023-07-16 08:40:55 2023-07-16 08:33:23 2023-07-16 08:32:32
   2023-07-16 08:18:40
