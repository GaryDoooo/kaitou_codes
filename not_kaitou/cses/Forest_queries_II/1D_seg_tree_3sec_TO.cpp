#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], n, q, b, p[1005][1005];

void input_map() {
    char s[1005];
    for (int y = 1; y <= n; y++) {
        scanf("%s", s);
        int i = 0;
        for (int x = 1; x <= n; x++) {
            while (s[i] != '.' and s[i] != '*') i++;
            a[x][y] = (s[i++] == '*');
        }
    }
}

struct node {
    int v;               // total trees in the range;
    int yt, yb, xl, xr;  // boundry of Y top, Y bottom, X left and X right
    int cut_x, mid;
};

node t[4123456];

void build(int i, int yt, int yb, int xl,
           int xr) {  // return pointer to the new node
    t[i] = {0, yt, yb, xl, xr};
    if (yt == yb and xl == xr) {
        t[i].v    = a[xl][yb];
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
    t[i].v = t[i << 1].v + t[i << 1 | 1].v;
}

int query(int i, int yt, int yb, int xl, int xr) {
    if (t[i].yt >= yt and t[i].yb <= yb and t[i].xl >= xl and t[i].xr <= xr)
        return t[i].v;
    int res = 0;
    if (t[i].cut_x) {
        int mid = (t[i].xr + t[i].xl) / 2;
        if (mid >= xl) res = query(i << 1, yt, yb, xl, xr);
        if (mid < xr) res += query(i << 1 | 1, yt, yb, xl, xr);
    } else {
        int mid = (t[i].yt + t[i].yb) / 2;
        if (mid >= yt) res = query(i << 1, yt, yb, xl, xr);
        if (mid < yb) res += query(i << 1 | 1, yt, yb, xl, xr);
    }
    return res;
}

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
            for (int i = p[x][y]; i; i >>= 1) t[i].v += delta;
        } else {
            int yt, yb, xl, xr, y1, x1, y2, x2;
            scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
            yt = min(y1, y2), yb = max(y1, y2);
            xl = min(x1, x2), xr = max(x1, x2);
            printf("%d\n", query(1, yt, yb, xl, xr));
        }
    }
}

