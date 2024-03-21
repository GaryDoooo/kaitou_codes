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

static inline void putint(long x) {
    char s[20];
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
    static int p[N], d[N];   // parent, degree
    static long h[N], s[N];  // distance sum, size
    static int o[N];         // traversal order

    int n;
    scanf("%d", &n);

    // Step 0: Init
    for (int i = 1; i <= n; i++) {
        s[i] = 1;
    }

    // Step 1: Treeification
    for (int i = 1; i < n; i++) {
        int a = getint();
        int b = getint();

        if (!p[a]) {
            p[a] = b;
            d[b]++;
        } else {
            int op = p[b];
            p[b]   = a;
            d[a]++;
            while (op) {
                int gp = p[op];
                d[op]--;
                d[b]++;
                p[op] = b;
                b     = op;
                op    = gp;
            }
        }
    }
    // 有趣的是他这个建树的路子。先收到一个边随机选一个做父亲
    // 然后如果后面有需要在把之前的父子关系反向
    // 反正最后每个叶子都指向父亲，父亲那里有记录有多少儿子，但是不记录是谁。

    for (int i = 1; i <= n; i++) {
        printf("%d=%d %d\n ", i, p[i], d[i]);
    }
    // Step 2: Travel up from leaves to root, recording sum of distances to
    // children
    int j = 1;
    for (int i = 1; i <= n; i++) {
        int e = i;
        while (p[e] && d[e] == 0) {
            o[j++] = e;  // Record traversal order so we can go back in reverse
            // 这里从叶子节点出发倒推，如果有节点入度为零则被处理。
            // 记录处理的顺序这样后面就也不需要递归便利，翻过来顺序处理就行
            // 但是不适合需要递归算法从每个儿子读取数据再处理的。
            // 而且这里从1到n循环一遍，只保证所有零入度叶子被访问，
            // 后面摘掉叶子变为零入度的父亲节点们都是在while循环里面被访问的
            // 我觉得他这里不用递归主要是为了提高速度，复杂度还是一样的
            d[e]--;
            int pe = p[e];
            s[pe] += s[e];
            h[pe] += h[e] + s[e];
            e = pe;
            d[e]--;
        }
    }
    for (int i = 1; i <= j; i++) printf("%d\n", o[i]);

    // Step 3: Travel down from top to leaves, calculating final sums
    while (--j) {
        int e  = o[j];
        int pe = p[e];

        // Sum and size of parent without self
        long ps = s[pe] - s[e];
        long ph = h[pe] - h[e] - s[e];

        s[e] += ps;
        h[e] += ph + ps;
    }

    for (int i = 1; i <= n; i++) {
        putint(h[i]);
        putchar_unlocked(' ');
    }
    putchar_unlocked('\n');
}
