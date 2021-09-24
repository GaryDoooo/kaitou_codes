#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x * f;
}
int main() {
    int n = read(), m = read(), s = read(), t = read();
    vector<int> edge[n + 1], weight[n + 1];
    int right = 0, left = 1e9, done[n + 1];
    memset(edge, 0, sizeof(edge));
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        edge[u].push_back(v);
        weight[u].push_back(w);
        edge[v].push_back(u);
        weight[v].push_back(w);
        right = max(right, w);
        left  = min(left, w);
    }
    while (left < right) {
        int mid = (left + right) / 2;
        stack<int> todo;
        todo.push(s);
        memset(done, 0, sizeof(done));
        done[s] = 1;
        while (!todo.empty()) {
            int start = todo.top();
            todo.pop();
            for (int i = 0; i < edge[start].size(); i++) {
                if (done[edge[start][i]]) continue;
                if (weight[start][i] <= mid) {
                    done[edge[start][i]] = 1;
                    todo.push(edge[start][i]);
                }
            }
        }
        if (done[t]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left;
}

