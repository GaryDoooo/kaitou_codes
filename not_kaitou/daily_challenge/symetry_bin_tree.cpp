#include <bits/stdc++.h>
using namespace std;
struct nodes {
    int value, left, right;
};
nodes node[1000005];
int n, res = 0;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
vector<int> dfs(int index, int depth) {
    // res = max(res, depth);
    vector<int> left(0), right(0);
    if (node[index].left > 0) left = dfs(node[index].left, depth + 1);
    // else left.push_back(depth << 10);
    if (node[index].right > 0) right = dfs(node[index].right, depth + 1);
    // else right.push_back(depth << 10);
    if (left.size() == right.size()) {
        // vector<int> right_mirror(right.rbegin(), right.rend());
        bool equal = true;
        for (auto lit = left.begin(), rit = right.end() - 1; lit != left.end(); ++lit, rit--) {
            if (*lit != *rit) { equal = false; break;}
        }
        if (equal) {
            res = max(res, (int)(left.size() + right.size() + 1));
        }
    }
    left.insert(left.end(), (depth << 10) + node[index].value);
    left.insert(left.end(), right.begin(), right.end());
    // for (auto i : left) cout << i << " ";
    // cout << endl;
    return left;
}
int main() {
    n = read();
    for (register int i = 1; i <= n; i++) node[i].value = read();
    for (register int i = 1; i <= n; i++) node[i].left = read(), node[i].right = read();
    dfs(1, 0);
    cout << res;
}