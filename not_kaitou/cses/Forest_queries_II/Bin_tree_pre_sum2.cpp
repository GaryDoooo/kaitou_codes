#include <bits/stdc++.h>
using namespace std;

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
        putchar_unlocked('\n');
        return;
    }
    if (x < 0) {
        putchar_unlocked('-');
        x = -x;
    }
    while (x) {
        s[i++] = (x % 10) + '0';
        x /= 10;
    }
    while (i--) {
        putchar_unlocked(s[i]);
    }
    putchar_unlocked('\n');
}

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
            i /= 2;
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
node y_tree[2050];
int a[1005][1005], n, q, b, t_cnt, n0;
int ps[1005][1005];  // pre sum

void input_map() {
    for (int y = 1; y <= n; y++) {
        char c;
        for (int x = 1; x <= n; x++) {
            c = getchar_unlocked();
            while (c != '.' and c != '*') c = getchar_unlocked();
            a[x][y]  = (c == '*');
            ps[x][y] = ps[x - 1][y] + ps[x][y - 1] - ps[x - 1][y - 1] + a[x][y];
        }
    }
}

void build_1024_tree() {
    for (int i = n0 + 1; i <= n0 + n; i++) {
        int u = i;
        do {
            if (y_tree[u].has_tree)
                y_tree[u].div++;
            else if (((u & 1) == 0) or u == 1) {
                t[++t_cnt].build(n);
                y_tree[u] = {1, t_cnt, 1};
            }
            u /= 2;
        } while (u);
    }
}

void change(int target_x, int target_y, int delta) {
    target_y = n + 1 - target_y;
    do {
        int y_i = target_y + n0;
        while (!y_tree[y_i].has_tree) y_i /= 2;
        t[y_tree[y_i].tree_index].assign_range(target_x, delta);
        target_y -= y_tree[y_i].div;
    } while (target_y > 0);
}

int query(int target_x, int target_y) {
    if (target_x <= 0 or target_y <= 0) return 0;
    int y_i = n0 + n + 1 - target_y;
    int res = ps[target_x][target_y];
    while (y_i) {
        if (y_tree[y_i].has_tree)
            res += t[y_tree[y_i].tree_index].get_leaf_value(target_x);
        y_i /= 2;
    }
    return res;
}

int main() {
    n = getint(), q = getint();
    n0 = (1 << (int)trunc(log2(n - 1)) + 1) - 1;
    input_map();
    build_1024_tree();
    while (q--) {
        b = getint();
        if (b == 1) {
            int y = getint(), x = getint();  //, y;
            int delta = (a[x][y] == 1 ? -1 : 1);
            a[x][y] ^= 1;
            change(x, y, delta);
        } else {
            int yt, yb, xl, xr, y1 = getint(), x1 = getint(), y2 = getint(),
                                x2 = getint();
            yt = min(y1, y2), yb = max(y1, y2);
            xl = min(x1, x2), xr = max(x1, x2);
            putint(query(xr, yb) + query(xl - 1, yt - 1) - query(xr, yt - 1) -
                   query(xl - 1, yb));
        }
    }
}

