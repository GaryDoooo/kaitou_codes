#include <bits/stdc++.h>
using namespace std;
int a[51234], type[51234], n, k, res, c[51234];
struct eat_chain {
    set<int> roots;
};
eat_chain chain[51234];

int get_root(int* a, int i) {
    int idx = i;
    while (a[idx]) idx = a[idx];
    if (idx != i) a[i] = idx;
    return idx;
}
void combine_chain(int to_chain, int change_chain, int ref_root,
                   int value_to_ref, bool remove) {
    c[change_chain] = to_chain;
    if (remove) chain[change_chain].roots.erase(ref_root);
    chain[to_chain].roots.insert(chain[change_chain].roots.begin(),
                                 chain[change_chain].roots.end());
    int offset = value_to_ref - type[ref_root];
    if (offset == 0) return;
    if (offset < 0) offset += 3;
    for (int r : chain[change_chain].roots) {
        // if (r == ref_root) continue;
        type[r] += offset;
        if (type[r] > 3) type[r] -= 3;
    }
}

bool combine(int i1, int i2) {
    int r1 = get_root(a, i1);
    int r2 = get_root(a, i2);
    if (r1 != r2) {
        int c1 = get_root(c, r1), c2 = get_root(c, r2);
        if (c1 == c2) {
            if (type[r1] != type[r2]) return false;
        } else if (chain[c1].roots.size() == 1) {
            a[r1] = r2;
        } else if (chain[c2].roots.size() == 1) {
            a[r2] = r1;
        } else {
            combine_chain(c1, c2, r2, type[r1], true);
            a[r2] = r1;
        }
    }
    return true;
}
int main() {
    int e, x, y;
    // int eat[4]  = {0, 2, 3, 1};
    // int food[4] = {0, 3, 1, 2};
    scanf("%d%d", &n, &k);
    // type[1] = 1;
    for (int i = 1; i <= n; i++) {
        type[i] = 1;
        chain[i].roots.insert(i);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &e, &x, &y);
        if (x > n or y > n) {
            res++;
            continue;
        }
        if (e == 1) {
            if (!combine(x, y)) {
                res++;
                continue;
            }
        } else {
            int r1 = get_root(a, x), r2 = get_root(a, y);
            if (r1 == r2) {
                res++;
                continue;
            }
            int t1 = type[r1], t2 = type[r2];
            int c1 = get_root(c, r1), c2 = get_root(c, r2);
            if (c1 == c2) {
                int relationship = t1 - t2;
                if (relationship < 0) relationship += 3;
                if (relationship != 1) {
                    res++;
                    continue;
                }
            } else {
                int t2_to = t1 - 1;
                if (t2_to == 0) t2_to = 3;
                combine_chain(c1, c2, r2, t2_to, false);
            }
        }
    }
    cout << res;
}
