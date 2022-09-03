#include <bits/stdc++.h>
using namespace std;
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
    putchar('\n');
}
////////////////////////
struct tr {
    int l, r, v;
};
// struct point_of_interest {
//     int day, order;
// };
// point_of_interest p[412345];
// bool cmp(point_of_interest const& p1, point_of_interest const& p2) {
//     return p1.day < p2.day;
// }
vector<tr> t(4000005);
// unordered_map<int, int> idx;
int o[412345][3];
int n, tt, a, b, idx[11234567], p[812345], p_cnt;
// set<int> p;
void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l < r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}
// void sum_up(int u) {
//     int l = u << 1, r = u >> 1 | 1;
//     t[u].v = t[l].v + t[r].v + (t[l].r - t[l].l + 1) * t[l].add +
//              (t[r].r - t[r].l + 1) * t[r].add;
// }
// void push_add_down(int u) {
//     if (t[u].l == t[u].r) return;
//     // t[u].v += t[u].add;
//     else {
//         t[u << 1 | 1].v += t[u].v;
//         t[u << 1].v += t[u].v;
//         // sum_up(u);
//     }
//     t[u].v = 0;
// }
int get_v(int u, int x) {
    // push_add_down(u);
    if (t[u].l == t[u].r) return t[u].v;
    int l = u << 1;
    int r = l | 1;
    t[r].v += t[u].v;
    t[l].v += t[u].v;
    t[u].v  = 0;
    int mid = t[u].l + t[u].r >> 1, res;
    if (mid >= x)
        res = get_v(l, x);
    else
        res = get_v(r, x);
    // sum_up(u);
    return res;
}
void add(int u, int l, int r) {
    if (t[u].l >= l and t[u].r <= r) {
        t[u].v++;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= l) add(u << 1, l, r);
    if (mid < r) add(u << 1 | 1, l, r);
}
int main() {
    n = read(), tt = read();
    // scanf("%d%d", &n, &tt);
    // build(1, 1, n);
    for (int i = 0; i < tt; i++) {
        a = read();
        // scanf("%d", &a);
        if (a) {
            o[i][0] = a;
            b       = read();
            // scanf("%d", &b);
            o[i][1]    = b;
            p[p_cnt++] = b;
            // p.insert(b);
            // p[poi_cnt++]=b;
            // p[poi_cnt++].day = b;
            // printf("%d\n", get_v(1, b));
        } else {
            // scanf("%d%d\n", &a, &b);
            o[i][1] = a = read();
            o[i][2] = b = read();
            p[p_cnt++]  = a;
            p[p_cnt++]  = b;
            // p.insert(b);
            // p.insert(a);
            // add(1, a, b);
        }
    }
    sort(p, p + p_cnt);
    int i = 0;
    for (int j = 0; j < p_cnt; j++) {
        idx[p[j]] = i++;
        while (p[j + 1] == p[j]) j++;
    }
    // for (int j : p) idx[j] = i++;
    build(1, 0, i - 1);
    for (int i = 0; i < tt; i++) {
        if (o[i][0]) write(get_v(1, idx[o[i][1]]));
        // printf("%d\n", get_v(1, idx[o[i][1]]));
        else
            add(1, idx[o[i][1]], idx[o[i][2]]);
    }
}
