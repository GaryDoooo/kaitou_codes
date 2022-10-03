#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
};
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int n = read(), u, v, w, res = 0;
    edge e[n];
    unordered_set<int> node[n + 1];
    int node_min[n + 1];
    memset(node_min, 0, sizeof(node_min));
    for (int i = 0; i < n - 1; i++) {
        u = read(), v = read(), w = read();
        e[i].u = u; e[i].v = v; e[i].w = w;
        node[u].insert(i);
        node[v].insert(i);
    }
    stack<int> todo;
    for (int i = 1; i <= n; i++) {
        if (node[i].size() == 1) todo.push(i);
    }
    for (int k = 1; k < n; k++) {
        int i = todo.top(); todo.pop();
        for (auto j : node[i]) {
            u = e[j].u; v = e[j].v; w = e[j].w;
            if (v == i) swap(u, v);
            node[v].erase(j);
        }
        res = min(res, node_min[u] + node_min[v] + w);
        node_min[v] = min(node_min[v], node_min[u] + w);
        if (node[v].size() == 1) todo.push(v);
    }
    cout << res;
}