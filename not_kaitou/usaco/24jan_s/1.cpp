#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r;
    int m;
};
node t[412345];
int n, q_cnt, c_max, c[112345], last_0[112345];

void bring_up(int n) { t[n].m = max(t[n << 1].m, t[n << 1 | 1].m); }

void build(int n, int l, int r) {
    t[n] = {l, r, 0};
    if (l == r) {
        t[n].m = c[l];
        return;
    }
    int mid = l + r >> 1;
    build(n << 1, l, mid);
    build(n << 1 | 1, mid + 1, r);
    bring_up(n);
}

int query(int n, int l, int r) {
    if (t[n].l >= l and t[n].r <= r) return t[n].m;
    int mid = t[n].l + t[n].r >> 1;
    int res = 0;
    if (mid >= l) res = query(n << 1, l, r);
    if (mid < r) res = max(res, query(n << 1 | 1, l, r));
    return res;
}

void change(int n, int target, int change_to) {
    if (t[n].l == t[n].r) {
        t[n].m = change_to;
        return;
    }
    int mid = t[n].l + t[n].r >> 1;
    if (target <= mid)
        change(n << 1, target, change_to);
    else
        change(n << 1 | 1, target, change_to);
    bring_up(n);
}

int solve() {
    scanf("%d %d %d", &n, &q_cnt, &c_max);
    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
        if (c[i])
            last_0[i] = last_0[i - 1];
        else
            last_0[i] = i;
    }
    vector<pair<int, int>> q;
    for (int i = 0; i < q_cnt; i++) {
        int a, b;
        scanf("%d %d", &b, &a);
        q.push_back(make_pair(a, b));
    }
    sort(q.begin(), q.end());
    build(1, 1, n);
    int changed;
    do {
        changed = 0;
        for (auto p : q) {
            int h = p.first, a = p.second;
            int max_1_to_a = query(1, 1, a);
            int lower_limit, upper_limit = c[h] - 1;
            if (h - a == 1)
                lower_limit = 1;
            else
                lower_limit = query(1, a + 1, h - 1);
            int max_1_to_h_minus_1 = max(lower_limit, max_1_to_a);
            if (max_1_to_h_minus_1 > upper_limit) {
                if (last_0[h] == h)  // can change c[h]
                {
                    if (max_1_to_h_minus_1 + 1 > c_max) return 0;
                    change(1, h, c[h] = max_1_to_h_minus_1 + 1);
                    changed = 1;
                } else
                    return 0;
            }
            if (lower_limit > max_1_to_a) {
                if (last_0[a] == 0 or lower_limit > c_max) return 0;
                change(1, last_0[a], c[last_0[a]] = lower_limit);
                changed = 1;
            }
        }
    } while (changed);
    for (int i = 1; i <= n; i++) {
        if (c[i])
            printf("%d", c[i]);
        else
            printf("1");
        if (i < n) printf(" ");
    }
    printf("\n");
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        if (solve()) continue;
        puts("-1");
    }
}
