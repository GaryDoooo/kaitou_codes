#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r, f, cnt = 1;
};
node a[112345];
int n = 30000, t, p = 30000;
int get_root(int idx) {
    while (a[idx].f) idx = a[idx].f;
    return idx;
}
void connect_i_to_j(int i, int j) {
    // i series to the tail of j series
    // i series is left, j is right
    int rl = get_root(i), rr = get_root(j);
    a[++p].l = rl;
    a[p].r   = rr;
    a[p].cnt = a[rl].cnt + a[rr].cnt;
    a[rl].f = a[rr].f = p;
}
int how_many_on_left(int i) {
    int res = 0;
    while (a[i].f) {
        if (a[a[i].f].r == i) res += a[a[a[i].f].l].cnt;
        i = a[i].f;
    }
    return res;
}
int cnt_between(int i, int j) {
    int ci = how_many_on_left(i), cj = how_many_on_left(j);
    return abs(ci - cj) - 1;
}
int main() {
    char c;
    int i, j;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%c %d %d\n", &c, &i, &j);
        // cout << c << " " << i << " " << j << endl;
        if (c == 'M')
            connect_i_to_j(i, j);
        else if (c == 'C') {
            int ri = get_root(i), rj = get_root(j);
            if (ri != rj) {
                puts("-1");
                continue;
            }
            printf("%d\n", cnt_between(i, j));
        }
    }
}
