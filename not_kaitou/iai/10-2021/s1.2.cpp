#include <bits/stdc++.h>
using namespace std;
struct number {
    vector<int> left, right;
};
int n, m, c, b;
number a[305];
unordered_set<int> l[305];
unordered_set<int> r[305];
void count_left(int i) {
    if (l[i].size() > 0) return;
    for (auto j : a[i].left) {
        l[i].insert(j);
        count_left(j);
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
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c >> b;
        a[b].right.push_back(c);
        a[c].left.push_back(b);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        count_left(i);
        count_right(i);
        if (l[i].size() + r[i].size() == n - 1) res++;
    }
    cout << res;
}
