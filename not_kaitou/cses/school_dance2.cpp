#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int in_d[1005];
vector<int> e[1005];
int edge_available, picked[1005];  // picked
int pick[505], ttl_pairs;          // boy pick girl #
int res, res_pick[505];
int boys[505];  // index of boys

bool cmp(int x, int y) { return in_d[x] < in_d[y]; }

void print_exit() {
    printf("%d\n", res);
    for (int i = 1; i <= n; i++)
        if (res_pick[i]) printf("%d %d\n", i, res_pick[i] - 500);
    exit(0);
}

void dfs(int cnt) {
    // cout << cnt << " ";
    if (cnt > n) {
        if (ttl_pairs > res) {
            res = ttl_pairs;
            // cout << res << endl;
            memcpy(res_pick, pick, sizeof(pick));
            print_exit();
        }
        return;
    }
    if (edge_available + ttl_pairs <= res) return;
    sort(boys + cnt, boys + 1 + n, cmp);
    while (in_d[boys[cnt]] == 0) cnt++;
    if (cnt > n) {
        if (ttl_pairs > res) {
            res = ttl_pairs;
            memcpy(res_pick, pick, sizeof(pick));
        }
        print_exit();
        return;
    }
    int b = boys[cnt];
    stack<int> removed_edges;
    picked[b] = 1;
    ttl_pairs++;
    sort(e[b].begin(), e[b].end(),
         cmp);  // sort all the connected girls by their in-degree
    for (int g : e[b]) {
        if (picked[g]) continue;
        removed_edges.push(g);
        in_d[g]--;  // since this boy will be picked anyway, all unpicked girls
                    // connected has her in-degree -1
        edge_available--;  // removed all edges connects to available girls
    }
    // in-degree of this boy doesn't need be changed, since the sorting will
    // start after him
    for (int g : e[b]) {
        if (picked[g]) continue;
        picked[g] = 1;
        stack<int> removed_edges;
        for (int other_connected_boys : e[g]) {
            if (picked[other_connected_boys]) continue;
            removed_edges.push(other_connected_boys);
            in_d[other_connected_boys]--;  // reduce all other connected boys
            edge_available--;  // also kill all the edges connect to this girl
                               // and to available boys
        }
        pick[b] = g;
        dfs(cnt + 1);
        edge_available += removed_edges.size();
        while (removed_edges.size()) {
            in_d[removed_edges.top()]++;
            removed_edges.pop();
        }
        picked[g] = 0;
    }
    edge_available += removed_edges.size();
    while (removed_edges.size()) {
        in_d[removed_edges.top()]++;
        removed_edges.pop();
    }
    ttl_pairs--;
    picked[b] = 0;
    pick[b]   = 0;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        b += 500;
        e[a].push_back(b);
        e[b].push_back(a);
        in_d[a]++;
        in_d[b]++;
    }
    edge_available = k;
    for (int i = 1; i <= n; i++) boys[i] = i;
    // sort(boys + 1, boys + 1 + n, cmp);
    // for (int i = 1; i <= n; i++) printf("%d ", boys[i]);
    dfs(1);
    printf("%d\n", res);
    for (int i = 1; i <= n; i++)
        if (res_pick[i]) printf("%d %d\n", i, res_pick[i] - 500);
}
