#include <bits/stdc++.h>
using namespace std;
class seg_tree {
public:
    int n;

private:
    int n0;
    vector<int> v;

public:
    seg_tree(int n_) {
        n  = n_;
        n0 = (1 << (int)trunc(log2(n - 1)) + 1) - 1;
        v.reserve(n * 4);
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

int main() {
    static int a[22];
    seg_tree t(20);
    for (int i = 0; i < 22; i++) {
        int target = rand() % 20 + 1;
        int delta  = rand() % 3 + 1;
        printf("Change %d to end by %d. ", target, delta);
        for (int j = target; j <= 20; j++) a[j] += delta;
        t.assign_range(target, delta);
        bool OK = true;
        for (int j = 1; j <= 20; j++)
            if (a[j] != t.get_leaf_value(j)) OK = false;
        if (!OK)
            puts("N");
        else
            puts("OK");
    }
    // printf("%d", t.v[3]);
}

