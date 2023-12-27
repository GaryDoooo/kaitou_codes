#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], n, q, b;
int ps[1005][1005];  // pre sum
int p[1005][1005];   // pointer to the leaf
// int pc[1005][1005];  // pointer to the highest level block whose upper left
//                      // corner is this cell

void input_map() {
    char s[1005];
    for (int y = 1; y <= n; y++) {
        scanf("%s", s);
        int i = 0;
        for (int x = 1; x <= n; x++) {
            while (s[i] != '.' and s[i] != '*') i++;
            a[x][y]  = (s[i++] == '*');
            ps[x][y] = ps[x - 1][y] + ps[x][y - 1] - ps[x - 1][y - 1] + a[x][y];
        }
    }
}

struct node {
    int v;  // prev_sum 1,1 to x,y when it's the leaf
    // when not leaf v is not zero that is a value to push down.
    int yt, yb, xl, xr;  // boundry of Y top, Y bottom, X left and X right
    int cut_x, mid;
};

node t[4123456];

void build(int i, int yt, int yb, int xl,
           int xr) {  // return pointer to the new node
    t[i] = {0, yt, yb, xl, xr};
    // if (pc[xl][yt] == 0) pc[xl][yt] = i;
    if (yt == yb and xl == xr) {
        t[i].v    = ps[xl][yb];
        p[xl][yb] = i;
        return;
    }
    if (yb - yt > xr - xl) {
        int mid = t[i].mid = (yb + yt) / 2;
        build(i << 1, yt, mid, xl, xr);
        build(i << 1 | 1, mid + 1, yb, xl, xr);
    } else {
        t[i].cut_x = 1;
        int mid = t[i].mid = (xl + xr) / 2;
        build(i << 1, yt, yb, xl, mid);
        build(i << 1 | 1, yt, yb, mid + 1, xr);
    }
}

int query(int i, int x, int y) {
    int res = 0;
    for (int i = p[x][y]; i; i /= 2) res += t[i].v;
    return res;
}

void change(int i, int target_x, int target_y, int delta) {
    if (t[i].yt >= target_y and t[i].xl >= target_x) {
        t[i].v += delta;
        return;
    }
    if (t[i].cut_x) {
        int mid = (t[i].xr + t[i].xl) / 2;
        if (mid >= target_x) change(i << 1, target_x, target_y, delta);
        change(i << 1 | 1, target_x, target_y, delta);
    } else {
        int mid = (t[i].yt + t[i].yb) / 2;
        if (mid >= target_y) change(i << 1, target_x, target_y, delta);
        change(i << 1 | 1, target_x, target_y, delta);
    }
}
//
int main() {
    scanf("%d %d", &n, &q);
    input_map();
    build(1, 1, n, 1, n);
    while (q--) {
        scanf("%d", &b);
        if (b == 1) {
            int x, y;
            scanf("%d %d", &y, &x);
            int delta = (a[x][y] == 1 ? -1 : 1);
            a[x][y] ^= 1;
            change(1, x, y, delta);
        } else {
            int yt, yb, xl, xr, y1, x1, y2, x2;
            scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
            yt = min(y1, y2), yb = max(y1, y2);
            xl = min(x1, x2), xr = max(x1, x2);
            printf("%d\n", query(1, xr, yb) + query(1, xl - 1, yt - 1) -
                               query(1, xr, yt - 1) - query(1, xl - 1, yb));
        }
    }
}

