#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct edge {
    int to, len;
};
struct node {
    int one_side_country_cnt = 0, removed_neighbors_cnt = 0;
    // vector<int> removed_neighbors;
    vector<edge> edges;
};
node a[1123456];
int n, done[1123456];
ll res;
queue<int> q;
void add_edge(int from, int to, int len) { a[from].edges.push_back({to, len}); }
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
        // cout << a << b << c << endl;
    }
    for (int i = 1; i <= n; i++)
        if (a[i].edges.size() == 1) {
            done[i] = 1;
            q.push(i);
            // cout << i << endl;
        }
    // cout << a[5].edges.size() << endl;
    // for (auto e : a[5].edges) cout << e.to << " " << e.len << endl;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        done[now] = 1;
        for (auto edge : a[now].edges) {
            if (done[edge.to]) continue;
            // cout << now << " " << edge.len << " " <<
            // a[now].one_side_country_cnt
            //      << " " << edge.to << endl;
            res += edge.len * abs(n - (1 + a[now].one_side_country_cnt) * 2);
            a[edge.to].one_side_country_cnt += 1 + a[now].one_side_country_cnt;
            a[edge.to].removed_neighbors_cnt += 1;
            if (a[edge.to].removed_neighbors_cnt + 1 ==
                a[edge.to].edges.size()) {
                // done[edge.to]=1;
                q.push(edge.to);
            }
            break;
        }
    }
    cout << res << endl;
}
