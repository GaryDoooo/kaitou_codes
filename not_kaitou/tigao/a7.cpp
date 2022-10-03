#include <bits/stdc++.h>
using namespace std;
struct node {
    int value = 0, preset = 0;
    int r, c, s;
};
int g[30], v;
node a[90];

void set_bit1(int* i, int p) { *i |= (1 << p); }
bool read_bit(int i, int p) { return (i & (1 << p)) > 0; }
void set_bit0(int* i, int p) { *i &= (~(1 << p)); }
void set_value(int idx, int p) {
    a[idx].value = p;
    set_bit1(&g[a[idx].r], p);
    set_bit1(&g[a[idx].c], p);
    set_bit1(&g[a[idx].s], p);
}
void unset_value(int idx, int p) {
    a[idx].value = 0;
    set_bit0(&g[a[idx].r], p);
    set_bit0(&g[a[idx].c], p);
    set_bit0(&g[a[idx].s], p);
}
vector<int> available_values(int idx) {
    int mask = 0;
    vector<int> res;
    // mask = ~mask;
    mask |= g[a[idx].r];
    mask |= g[a[idx].c];
    mask |= g[a[idx].s];
    for (int i = 1; i <= 9; i++)
        if (!read_bit(mask, i)) res.push_back(i);
    return res;
}

void dfs(int cnt) {
    if (cnt == 81) {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                int i = y * 9 + x;
                cout << a[i].value << " ";
            }
            cout << endl;
        }
        exit(0);
    }
    vector<int> options(10, 0);
    int picked_i;
    for (int i = 0; i < 81; i++) {
        if (a[i].value > 0) continue;
        vector<int> temp = available_values(i);
        if (temp.size() < options.size()) {
            options  = temp;
            picked_i = i;
        }
    }
    if (options.size() == 0 or options.size() > 9) return;
    // cout << endl << " pick: " << picked_i << ":";
    for (int v : options) {
        // cout << v << " ";
        set_value(picked_i, v);
        dfs(cnt + 1);
        unset_value(picked_i, v);
    }
}

int main() {
    int cnt = 0;
    for (int y = 0; y < 9; y++)
        for (int x = 0; x < 9; x++) {
            scanf("%d", &v);
            int i  = y * 9 + x;
            a[i].c = x;
            a[i].r = 9 + y;
            a[i].s = (x / 3) + (y / 3) * 3 + 18;
            if (v > 0) {
                a[i].preset = 1;
                set_value(i, v);
                cnt++;
            }
        }
    dfs(cnt);
    // vector<int> fd(10, 0);
    // cout << fd.size() << endl;
    // int t = 0;
    // set_bit1(&t, 4);
    // cout << t << endl;
    // set_bit1(&t, 2);
    // cout << t << endl;
    // set_bit0(&t, 4);
    // cout << t << endl;
    // cout << read_bit(t, 2) << endl;
    // cout << read_bit(t, 4) << endl;
}
