#include <bits/stdc++.h>
using namespace std;

class seg_tree {
private:
    int n, n0;
    vector<int> v;

public:
    void build(int n_) {
        n = n_;
        if (n == 1)
            n0 = 0;
        else
            n0 = (1 << (int)trunc(log2(n - 1)) + 1) - 1;
        v.resize(n * 4);
    }
    void assign_range(int leaf_start, int delta) {
        int i = leaf_start + n0;
        while (i) {
            if (i & 1) {
                v[i] += delta;
                if ((i & (i + 1)) == 0) return;
                i++;
            }
            i >>= 1;
        }
    }
    int get_leaf_value(int leaf_index) {
        int res = 0;
        int i   = leaf_index + n0;
        while (i) {
            res += v[i];
            i /= 2;
        }
        return res;
    }
};

seg_tree t[2050];
struct node {
    int has_tree, tree_index, div;
};
node y_tree[2050], x_tree[2050];
int a[1005][1005], n, q, b, t_cnt;
int ps[1005][1005];  // pre sum

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

void build_tree(node *tree) {
    int n = 1024;
    t[++t_cnt].build(1);
    tree[1] = {1, t_cnt, 1024};
    for (int i = 2; i < 2048; i += 2) {
        int size = (1 << (int)trunc(log2(n)));
        t[++t_cnt].build(size);
        tree[i] = {1, t_cnt, 1024 / size};
    }
}

void build_1024_tree() {
    build_tree(y_tree);
    build_tree(x_tree);
}

void chage(int target_x, int target_y, int delta) {
    if (target_x <= 0 or target_y <= 0) return;
    int x_i = target_x + 1023, y_i = target_y + 1023;
    while ((x_i & 1) and (y_i & 1)) {
        if (x_i == 1) break;
        x_i <<= 1, y_i <<= 1;
    }
    if (x_i & 1) {
        t[y_tree[y_i].tree_index].assign_range(target_x / y_tree[y_i].div,
                                               delta);
        change(target_x, target_y - y_tree[y_i].div, delta);
    } else {
        t[x_tree[x_i].tree_index].assign_range(target_y / x_tree[x_i].div,
                                               delta);
        change(target_x - x_tree[x_i].div, target_y, delta);
    }
}

int query(int target_x, int target_y) {
    int x_i = 2048 - target_x, y_i = 2048 - target_y;
    res = ps[target_x][target_y];
    while (x_i) {
        if (x_tree[x_i].has_tree)
            res += t[x_tree[x_i].tree_index].get_leaf_value(target_y /
                                                            x_tree[x_i].div);
        x_i <<= 1;
    }
    while (y_i) {
        if (y_tree[y_i].has_tree)
            res += t[y_tree[y_i].tree_index].get_leaf_value(target_x /
                                                            y_tree[y_i].div);
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &q);
    input_map();
    build_1024_tree();
    while (q--) {
        scanf("%d", &b);
        if (b == 1) {
            int x, y;
            scanf("%d %d", &y, &x);
            int delta = (a[x][y] == 1 ? -1 : 1);
            a[x][y] ^= 1;
            change(1025 - x, 1025 - y, delta);
        } else {
            int yt, yb, xl, xr, y1, x1, y2, x2;
            scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
            yt = min(y1, y2), yb = max(y1, y2);
            xl = min(x1, x2), xr = max(x1, x2);
            printf("%d\n", query(xr, yb) + query(xl - 1, yt - 1) -
                               query(xr, yt - 1) - query(xl - 1, yb));
        }
    }
}

