#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
struct node {
    long long value;
    int left_cnt, cnt, left, right;
};
long long put_node_in_tree(node n[], int i, long long value, int root) {
    if (value == n[root].value) {
        return (n[root].cnt++) + n[root].left_cnt;
    } else if (value > n[root].value) {
        if (n[root].right == 0) {
            n[root].right = i;
            return n[root].cnt + n[root].left_cnt;
        }
        return put_node_in_tree(n, i, value, n[root].right) + n[root].cnt +
               n[root].left_cnt;
    } else {
        n[root].left_cnt++;
        if (n[root].left == 0) {
            n[root].left = i;
            return 0;
        }
        return put_node_in_tree(n, i, value, n[root].left);
    }
}
int main() {
    int n = read(), m       = read();
    long long s[n + 1], res = 0;
    node nodes[n + 1];
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i]           = s[i - 1] + read() - m;
        nodes[i].value = s[i];
        nodes[i].left = nodes[i].right = nodes[i].left_cnt = 0;
        nodes[i].cnt                                       = 1;
        if (i > 1) res += put_node_in_tree(nodes, i, s[i], 1) + (s[i] >= 0);
    }
    cout << res << endl;
}
