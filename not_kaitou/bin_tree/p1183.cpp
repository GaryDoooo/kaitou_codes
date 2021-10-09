#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, r;
    cin >> n >> r;
    vector<int> v[n + 1];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    stack<int> todo;
    int done[n + 1];
    memset(done, 0, sizeof(done));
    todo.push(r);
    while (todo.size() > 0) {
        int node = todo.top();
        todo.pop();
        done[node] = 1;
        if (v[node].size() == 1) continue;
        if ((node == r && v[node].size() != 2) ||
            (node != r && v[node].size() != 3)) {
            cout << "no";
            return 0;
        }
        for (auto i : v[node])
            if (done[i] == 0) todo.push(i);
        // todo.push(v[r][1]);
    }
    cout << "yes" << endl;
}
