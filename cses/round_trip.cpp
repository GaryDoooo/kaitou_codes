#include <bits/stdc++.h>
using namespace std;
vector<int> e[212345];
int n, m, vis[212345];
vector<int> path;
bool solved = false;

void dfs(int u, int fa) {
    if (vis[u]) {
        if (path.size() >= 3) {
            int s = 1;
            for (int i = path.size() - 2; i >= 0; i--) {
                s++;
                if (path[i] == u) break;
            }
            cout << s << endl;
            cout << u << " ";
            for (int i = path.size() - 2; i >= 0; i--) {
                printf("%d ", path[i]);
                if (path[i] == u) break;
            }
            solved = true;
            return;
        }
        return;
    }
    vis[u] = 1;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == fa) continue;
        path.push_back(v);
        dfs(v, u);
        path.pop_back();
        if (solved) return;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        path.clear();
        path.push_back(i);
        dfs(i, 0);
        if (solved) return 0;
    }
    if (!solved) cout << "IMPOSSIBLE" << endl;
}
