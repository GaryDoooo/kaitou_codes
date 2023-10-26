#include <stdio.h>

#define N 100001
#define M 100001

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

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

// Limited Backtracking (Even, Itai & Shamir (1976))
void solve2() {
    static int p[M * 2], e[N * 4];
    static int q[2][M], qt[2], qh[2];
    static char t[2][M];  // temporary assignments
    static char r[M];     // permanent assigments
    int alive[2];

    int n = getint(), m = getint();

    for (int i = 0, j = 1; i < n; i++) {
        int as = getchar_unlocked();
        int a  = getint() * 2 + (as == '+');
        int bs = getchar_unlocked();
        int b  = getint() * 2 + (bs == '+');
        //
        // C *2 +1 is +C node, c*2 is -C node
        //
        e[j++] = b;
        e[j++] = p[a ^ 1];  // each family has two requests. use negative req 1
                            // pointing to positive req 2
        p[a ^ 1] = j - 2;

        e[j++]   = a;
        e[j++]   = p[b ^ 1];  // vis versa
        p[b ^ 1] = j - 2;
    }

    for (int c = 1; c <= m; c++) {
        if (!r[c]) {  // r[c] is permanent assignment
            // Start two evaluation branches for undecided variable
            for (int i = 0; i < 2; i++) {
                t[i][c] = i ? '+' : '-';  // temporarily assign
                // temp assign both states to the topping.
                qt[i] = qh[i] = 0;  // queue for each mode + and - head and tail
                q[i][qt[i]++] =
                    c * 2 + i;  // put the mode itself into the queue first
                alive[i] = 1;   // each mode is alive
            }
            int done = 0;
            while (!done) {
                for (int i = 0; i < 2; i++) {
                    if (alive[i]) {
                        if (qh[i] < qt[i]) {
                            int a = q[i][qh[i]++];
                            for (int j = p[a]; j; j = e[j + 1]) {
                                int b = e[j];
                                int x = b / 2, y = (b % 2) ? '+' : '-';
                                if (r[x] ||
                                    t[i][x]) {  // Check if permanent or
                                                // temporary as signment exists
                                    if ((r[x] && r[x] != y) ||
                                        (t[i][x] && t[i][x] != y)) {
                                        // Contradiction - branch is dead
                                        if (alive[1 - i]) {
                                            alive[i] = 0;
                                        } else {
                                            // Both branches dead
                                            puts("IMPOSSIBLE");
                                            return;
                                        }
                                    }
                                } else {
                                    t[i][x]       = y;
                                    q[i][qt[i]++] = b;
                                }
                            }
                        } else {
                            // This branch was succesful.
                            // Make it permanent.
                            for (int j = 0; j < qh[i]; j++) {
                                int b    = q[i][j];
                                r[b / 2] = (b % 2) ? '+' : '-';
                            }
                            // Roll back other branch's temporary assignments
                            int o = 1 - i;
                            for (int j = 0; j < qt[o]; j++) {
                                int b       = q[o][j];
                                t[o][b / 2] = 0;
                            }
                            done = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        putchar_unlocked(r[i]);
        putchar_unlocked(' ');
    }
    putchar_unlocked('\n');
}

typedef struct {
    int index, lowlink, comp;
} t_node;

// SCC (Tarjan)
void solve() {
    static int p[M * 2], e[N * 4];
    static t_node v[M * 2];
    static int s[M * 4], cs[M * 2];  // s = call stack, cs = component stack
    static char r[M];
    static int rc[M];
    int sp = 0, csp = 0, ci = 0;

    int n = getint(), m = getint() * 2 + 1;

    for (int i = 0, j = 1; i < n; i++) {
        int as = getchar_unlocked();
        int a  = getint() * 2 + (as == '+');
        int bs = getchar_unlocked();
        int b  = getint() * 2 + (bs == '+');

        e[j++]   = b;
        e[j++]   = p[a ^ 1];
        p[a ^ 1] = j - 2;

        e[j++]   = a;
        e[j++]   = p[b ^ 1];
        p[b ^ 1] = j - 2;
    }

    int k = 0;
    for (int i = 2; i <= m; i++) {
        if (!v[i].index) {
            v[i].index = v[i].lowlink = ++k;
            s[++sp]                   = i;
            s[++sp]                   = p[i];
            cs[++csp]                 = i;
        }
        while (sp) {
            int a = s[sp - 1], j = s[sp];
            if (j) {
                int b = e[j];
                s[sp] = e[j + 1];

                if (!v[b].index) {
                    v[b].index = v[b].lowlink = ++k;
                    s[++sp]                   = b;
                    s[++sp]                   = p[b];
                    cs[++csp]                 = b;
                } else if (!v[b].comp) {
                    v[a].lowlink = MIN(v[a].lowlink, v[b].index);
                }
            } else {
                if (v[a].index == v[a].lowlink) {
                    ci++;
                    int f;
                    do {
                        f     = cs[csp--];
                        int g = f / 2;
                        if (rc[g] == ci) {
                            puts("IMPOSSIBLE");
                            return;
                        } else if (rc[g] == 0) {
                            rc[g] = ci;
                            r[g]  = (f % 2) ? '+' : '-';
                        }
                        v[f].comp = ci;
                    } while (f != a);
                }

                if (sp > 2) {
                    int t        = s[sp - 3];
                    v[t].lowlink = MIN(v[t].lowlink, v[a].lowlink);
                }
                sp -= 2;
            }
        }
    }

    for (int i = 1; i <= m / 2; i++) {
        putchar_unlocked(r[i]);
        putchar_unlocked(' ');
    }
    putchar_unlocked('\n');
}

int main() { solve2(); }
