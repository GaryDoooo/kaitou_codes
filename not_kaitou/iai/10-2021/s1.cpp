#include <bits/stdc++.h>
using namespace std;
struct number {
    vector<int> left, right;
};
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
int n, m;
number a[305];
unordered_set<int> l[305];
unordered_set<int> r[305];
void count_left(int i) {
    if (l[i].size() > 0) return;
    // int res = 0;
    for (auto j : a[i].left) {
        l[i].insert(j);
        count_left(j);
        // l[i].merge(l[j]);
        for (int k : l[j]) l[i].insert(k);
    }
}
void count_right(int i) {
    if (r[i].size() > 0) return;
    for (auto j : a[i].right) {
        r[i].insert(j);
        count_right(j);
        for (int k : r[j]) r[i].insert(k);
    }
}
int main() {
    n = read(), m = read();
    for (int i = 0; i < m; i++) {
        int c = read(), b = read();
        a[b].right.push_back(c);
        a[c].left.push_back(b);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << endl;
    //     for (int j : a[i].left) cout << j << " ";
    //     cout << endl;
    //     for (int j : a[i].right) cout << j << " ";
    //     cout << endl;
    // }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        // if (count_left(i) + count_right(i) == n - 1) res++;
        count_left(i);
        count_right(i);
        if (l[i].size() + r[i].size() == n - 1) res++;
    }
    cout << res;
}
