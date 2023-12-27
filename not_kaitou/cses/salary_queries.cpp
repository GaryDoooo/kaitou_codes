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
/*
 *
 * Can use multiset to maintain the sorted list
 * All operations, insert, erase, lower_bound are log N
 * But distance is linear
 *
int main() {
    int n = read(), q = read();
    vector<int> x;
    multiset<int> a, rm, add;
    for (int i = 0; i < n; i++) x.push_back(read());
    vector<int> x0(x.begin(), x.end());
    sort(x.begin(), x.end());
    a.insert(x.begin(), x.end());
    // cout << "done" << endl;
    while (q--) {
        char c;
        do {
            c = getchar();
        } while (c != '!' && c != '?');
        int u = read(), v = read();
        // cout << "done" << endl;
        if (c == '!') {
            auto it   = a.lower_bound(x0[u - 1]);
            x0[u - 1] = v;
            a.erase(it);
            a.insert(v);
        } else {
            if (u > v) swap(u, v);
            auto it_l = a.lower_bound(u), it_r = a.upper_bound(v);
            // write(distance(it_l, it_r));
        }
    }
}*/

int t[1612345], op[212345][3], idx[412345];
int q, n1, n, n0;

struct p {
    int val, typ, order;
};

p a[412345];

bool cmp(const p& x, const p& y) { return x.val < y.val; }
// 比较函数的输入要带上&和const

void refresh_tree(int k) {
    // 这里需要k大于1，这样最后更新根节点1号
    while (k > 1) {
        k    = k / 2;
        t[k] = t[k * 2] + t[k * 2 + 1];
        //
        //
        // No Need to use k<<1 or k<< 1 | 1
        // Write in a normal way it's faster actually
        //
        //
        //
    }
}

int count_left_nodes(int v) {
    int res       = 0;
    const p value = {v, 0, 0};  // Here in cmp function, it needs to be const.
    // 使用lower bound减去数组的头部指针就是index
    // upper_bound(k) 和 lower_bound(k+1)效果是一样的。
    int k = lower_bound(a + 1, a + n1 + 1, value, cmp) - a + n0;
    if (k > n0 + n1) return n;
    while (k > 1) {
        if (k & 1) res += t[k - 1];
        k = k / 2;
    }
    return res;
}

int main() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = {read(), 0, i};
    n1 = n;
    for (int i = 1; i <= q; i++) {
        char c;
        do {
            c = getchar();
        } while (c != '!' && c != '?');
        int u = read(), v = read();
        if (c == '!') {
            a[++n1]  = {v, 1, i};
            op[i][1] = u, op[i][2] = v;
        } else {
            op[i][0] = 1;
            op[i][1] = u, op[i][2] = v;
        }
    }
    sort(a + 1, a + 1 + n1, cmp);
    //
    //把所有可能的工资的值都存在树里面，
    //还没有用到的未来的值，节点计数为零，当前工资节点计数为1
    //
    n0 = (1 << (int)trunc(log2(n1 - 1)) + 1) - 1;

    for (int i = 1; i <= n1; i++) {
        idx[a[i].typ * n + a[i].order] = n0 + i;
        t[n0 + i]                      = (a[i].typ == 0);
    }
    for (int i = n0; i > 0; i--) t[i] = t[i * 2] + t[i * 2 + 1];

    for (int i = 1; i <= q; i++) {
        int u = op[i][1], v = op[i][2];
        if (op[i][0]) {
            if (u > v) swap(u, v);
            write(count_left_nodes(v + 1) - count_left_nodes(u));
        } else {
            int i1 = idx[u], i2 = idx[n + i];
            idx[u] = i2;
            //
            // 一个人的工资可能被改变好几回，所以要
            // 记录新的工资在树上的节点位置
            // 最后跟节点的计数一直应该为n
            //
            t[i1] = 0;
            refresh_tree(i1);
            t[i2] = 1;
            refresh_tree(i2);
        }
    }
}

