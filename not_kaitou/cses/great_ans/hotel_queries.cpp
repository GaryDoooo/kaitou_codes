#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <limits.h>
#include <stdio.h>
// #include <algorithm>
// using namespace std;

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
// by not using algorithm's max, one of test is 0.01s faster which was 0.05s
static inline int max(int a, int b) { return a > b ? a : b; }

void solve() {
    static int x[1 << 20];
    int n = getint(), m = getint();
    int n0 = (1 << ((sizeof(int) * CHAR_BIT) - __builtin_clz(n - 1))) - 1;
    // n0 这里是n的最高位对应的数字减一，比如5，6，7，8就是8-1=7，9到16就是15
    // putint(n0);
    // putint(ONE_BASED_INDEX_OF_HIGHEST_SET_BIT(n));

    for (int i = 1; i <= n; i++) {
        x[n0 + i] = getint();
    }

    for (int i = n0; i > 0; i--) {
        x[i] = max(x[i * 2], x[i * 2 + 1]);
    }
    // This is actually a segment tree
    // for (int i = 0; i <= n + n0; i++) {
    //     printf("%02d : %d \t", i, x[i]);
    // }

    for (int i = 0; i < m; i++) {
        int r = getint();

        if (x[1] < r) {
            putchar_unlocked('0');
            // x[1] is the max of all
            //
        } else {
            int k = 2;
            while (k <= n0) {  // k<=n0 means k is not on the leaves.
                if (x[k] < r)
                    k++;  // must be one of the two is equal or greater than r
                k *= 2;   // move to the next level
            }
            if (x[k] < r) k++;

            putint(k - n0);
            x[k] -= r;
            k /= 2;      // get to the father node
            while (k) {  // while k>0 means k is still on the tree, root is 1
                x[k] = max(x[k * 2], x[k * 2 + 1]);
                k /= 2;
            }
        }
        putchar_unlocked(' ');
    }

    putchar_unlocked('\n');
}

int main() { solve(); }

