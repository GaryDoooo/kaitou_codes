#include <bits/stdc++.h>
using namespace std;
int n, res;
// unordered_set<int> e[212345];
vector<int> e[212345];

int go(int x, int fa) {
    // return 0 if the node is not exist after work
    // otherwise return 1
    if (x > 1 and e[x].size() == 1) return 1;
    int alive_son = 0;
    for (int son : e[x]) {
        if (son == fa) continue;
        if (go(son, x)) alive_son = son;
    }
    // cout << x << ".>" << alive_son << endl;
    if (alive_son)  // make a pair
    {
        res++;
        return 0;
    } else
        return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
        // e[a].insert(b);
        // e[b].insert(a);
    }
    // for (int i = 1; i <= n; i++) cout << e[i].size() << endl;
    go(1, 0);
    cout << res << endl;
}

