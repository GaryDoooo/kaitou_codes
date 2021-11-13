#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar(' ');
}
////////////////////////

int main() {
    int x = read(), n = read();
    struct light {
        int pos, order;
        bool operator<(const light& o) const { return pos < o.pos; }
    };
    light l[n + 2];
    for (int i = 0; i < n; i++) l[i] = {read(), i};
    l[n]     = {0, n};
    l[n + 1] = {x, n + 1};
    sort(l, l + n + 2);
    struct node {
        int pos, left, right;
    };
    node nodes[n + 2];
    nodes[n]     = {0, n, l[1].order};
    nodes[n + 1] = {x, l[n].order, n + 1};
    int res      = x - l[n].pos;
    for (int i = 1; i <= n; i++) {
        nodes[l[i].order] = {l[i].pos, l[i - 1].order, l[i + 1].order};
        res               = max(res, l[i].pos - l[i - 1].pos);
    }
    int output[n + 1];
    output[n] = res;
    for (int i = n - 1; i >= 1; i--) {
        int left  = nodes[i].left;
        int right = nodes[i].right;
        output[i] = res   = max(res, nodes[right].pos - nodes[left].pos);
        nodes[left].right = right;
        nodes[right].left = left;
    }
    for (int i = 1; i <= n; i++) write(output[i]);
}  
