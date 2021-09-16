#include <bits/stdc++.h>
using namespace std;
struct nodes {
    int value, left, right;
} node[1000005];
int res = 0, n, a[1000005], a_index = 0, cnt[1000005];
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int dfs(int index, int depth) {
    int count = 0, this_index;
    if (node[index].left > 0) count = dfs(node[index].left, depth + 1);
    a[this_index = a_index++] = (depth << 10) + node[index].value;
    if (node[index].right > 0) count += dfs(node[index].right, depth + 1);
    return cnt[this_index] = count + 1;
}
int *manacher() {
    int *b, *p, mem_size = sizeof(int) * ((n << 1) + 5);
    b = (int *)malloc(mem_size); // b(2 * n + 5, 0), p(2 * n + 5, 0);
    p = (int *)malloc(mem_size);
    b[0] = -2; b[1] = -1; b[(n << 1) + 2] = -3;
    for (register int i = 0, j = 2; i < n; i ++, j += 2) b[j] = a[i ], b[j + 1] = -1;
    register int c = 0, r = 0;
    for (register int i = 1; i <= n << 1; i++) {
        p[i] = (i < r ? min(r - i, p[(c << 1) - i]) : 0);
        while (b[i + p[i] + 1] == b[i - p[i] - 1]) p[i]++;
        if (i + p[i] > r) c = i, r = i + p[i];
    }
    return p;
}
int main() {
    n = read();
    for (register int i = 1; i <= n; i++) node[i].value = read();
    for (register int i = 1; i <= n; i++) node[i].left = read(), node[i].right = read();
    dfs(1, 0);
    int *p = manacher();
    for (register int i = 0, j = 2; i < n; i++, j += 2) {
        if (cnt[i] == p[j]) res = max(res, p[j]);
    }
    cout << res;
}