#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
int main() {
    int n = read(), m = read(), q = read();
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        g[v].push_back(u);
        g[u].push_back(v);
    }
    deque<int> todo;
    deque<int> dis;
    int odd_min[n + 1], even_min[n + 1];  //, min_dis[n + 1];
    // memset(odd, 0, sizeof(odd));
    // memset(even, 0, sizeof(even));
    // memset(min_dis, 100, sizeof(min_dis));
    memset(odd_min, 100, sizeof(odd_min));
    memset(even_min, 100, sizeof(even_min));
    todo.push_back(1);
    dis.push_back(0);
    even_min[1] = 0;
    while (!todo.empty()) {
        int s = todo.front();
        todo.pop_front();
        int d = dis.front() + 1;
        dis.pop_front();
        for (int t : g[s]) {
            if (d & 1) {
                if (d < odd_min[t]) {
                    odd_min[t] = d;
                    todo.push_back(t);
                    dis.push_back(d);
                }
            } else {
                if (d < even_min[t]) {
                    even_min[t] = d;
                    todo.push_back(t);
                    dis.push_back(d);
                }
            }
        }
    }
    // cout << endl;
    for (int i = 0; i < q; i++) {
        int t = read(), l = read();
        // cout << odd[a] << " " << even[a] << endl;
        if (l & 1) {
            if (odd_min[t] > m)
                printf("No\n");
            else if (l < odd_min[t])
                printf("No\n");
            else
                printf("Yes\n");
        } else {
            if (even_min[t] > m)
                printf("No\n");
            else if (l < even_min[t])
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
}
