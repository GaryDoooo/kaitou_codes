#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], n, q, b;

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
    int s[4];            // pointer to 4 son nodes;
};

node t[2123456];
int idx;  // end of the tree

void bring_up(int i) {
    t[i].v = 0;
    for (int j = 0; j < 4; j++) t[i].v += t[t[i].s[j]].v;
}

int build(int yt, int yb, int xl, int xr) {  // return pointer to the new node
    int i = ++idx;
    t[i]  = {0, yt, yb, xl, xr};
    if (yt == yb and xl == xr) {
        t[i].v = a[xl][yb];
        return i;
    }
    int midx = (xl + xr) / 2, midy = (yb + yt) / 2;
    int midx2 = midx + 1, midy2 = midy + 1;
    t[i].s[0] = build(yt, midy, xl, midx);
    if (midx2 <= xr) t[i].s[1] = build(yt, midy, midx2, xr);
    if (midy2 <= yb) t[i].s[2] = build(midy2, yb, xl, midx);
    if (midx2 <= xr and midy2 <= yb) t[i].s[3] = build(midy2, yb, midx2, xr);
    bring_up(i);
    return i;
}

void change(int i, int target_x, int target_y) {
    if (i == 0) return;
    if (target_x > t[i].xr or target_x < t[i].xl or target_y > t[i].yb or
        target_y < t[i].yt)
        return;
    if (t[i].xr == t[i].xl and t[i].yb == t[i].yt) {
        t[i].v = a[target_x][target_y];
        return;
    }
    for (int j = 0; j < 4; j++) change(t[i].s[j], target_x, target_y);
    bring_up(i);
}

int query(int i, int yt, int yb, int xl, int xr) {
    if (i == 0) return 0;
    if (yb < t[i].yt or yt > t[i].yb or xl > t[i].xr or t[i].xl > xr) return 0;
    if (t[i].yt >= yt and t[i].yb <= yb and t[i].xl >= xl and t[i].xr <= xr)
        return t[i].v;
    int res = 0;
    for (int j = 0; j < 4; j++) res += query(t[i].s[j], yt, yb, xl, xr);
    return res;
}

int main() {
    scanf("%d %d", &n, &q);
    input_map();
    int root = build(1, n, 1, n);
    while (q--) {
        scanf("%d", &b);
        if (b == 1) {
            int x, y;
            scanf("%d %d", &y, &x);
            // cout << y << " " << x << " " << a[x][y] << " ";
            // cout << delta << endl;
            a[x][y] ^= 1;
            change(root, x, y);
        } else {
            int yt, yb, xl, xr, y1, x1, y2, x2;
            scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
            yt = min(y1, y2), yb = max(y1, y2);
            xl = min(x1, x2), xr = max(x1, x2);
            printf("%d\n", query(root, yt, yb, xl, xr));
        }
    }
}

