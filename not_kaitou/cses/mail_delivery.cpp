#include <bits/stdc++.h>

using namespace std;
int n, m, vis[212345], dist[112345], degree[212345];
long long mask = (1 << 17) - 1;

unordered_set<long long> e[112345];
int path[212345], path_index, edge_passed;

// void dfs(int from) {
//     // if (from == 1) cout << edge_passed << endl;
//     // cout << edge_passed << endl;
//     if (from == 1 and edge_passed == m) {
//         for (int i = 1; i <= path_index; i++) printf("%d ", path[i]);
//         puts("1");
//         exit(0);
//     }
//     path[++path_index] = from;
//     vector<pair<long long, long long>> nxt;
//     for (auto i : e[from]) {
//         int to = i & mask, e_i = i >> 17;
//         if (vis[e_i]) continue;
//         // nxt.push_back(make_pair(dist[e_i], i));
//         nxt.push_back(make_pair(degree[to], i));
//     }
//     sort(nxt.rbegin(), nxt.rend());
//     degree[from]--;
//     for (auto i : nxt) {
//         int to = i.second & mask, e_i = i.second >> 17;
//         vis[e_i] = 1;
//         degree[to]--;
//         edge_passed++;
//         dfs(to);
//         degree[to]++;
//         edge_passed--;
//         vis[e_i] = 0;
//     }
//     degree[from]++;
//     path_index--;
// }
//
long long next_step(int from) {
    for (auto i : e[from]) {
        int to = i & mask, e_i = i >> 17;
        if (vis[e_i] == 0) return i;
    }

    // vector<pair<long long, long long>> nxt;
    // for (auto i : e[from]) {
    //     int to = i & mask, e_i = i >> 17;
    //     if (vis[e_i]) continue;
    //     // nxt.push_back(make_pair(dist[e_i], i));
    //     nxt.push_back(make_pair(degree[to], i));
    // }
    // sort(nxt.rbegin(), nxt.rend());
    // return nxt[0].second;
}

// int get_junction(vector<int> &path) {
//     for (auto i : path) {
//         if (degree[i]) return i;
//     }
//     return 0;
// }

vector<int> round_trip(int from, int first_trip_from_here) {
    vector<int> res, new_res;
    int to, e_i;
    res.push_back(from);
    int now = from;
    while (now != from or res.size() == 1) {
        long long i = next_step(now);
        to = i & mask, e_i = i >> 17;
        degree[to]--;
        degree[now]--;
        vis[e_i] = 1;
        edge_passed++;
        res.push_back(to);
        now = to;
    }
    // while (to = get_junction(res)) {
    //     vector<int> branch = round_trip(to);
    //     new_res.clear();
    //     int inserted = 0;
    //     for (int i = 0; i < res.size(); i++) {
    //         if (res[i] != to or inserted)
    //             new_res.push_back(res[i]);
    //         else {
    //             for (int j : branch) new_res.push_back(j);
    //             inserted = 1;
    //         }
    //     }
    //     swap(res, new_res);
    // }
    // queue<vector<int>> branches;
    // queue<int> junctions;
    for (int i : res) {
        if (i == from and first_trip_from_here == 0) {
            new_res.push_back(i);
            continue;
        }
        while (degree[i]) {
            vector<int> branch = round_trip(i, i != from);
            for (int j : branch) new_res.push_back(j);
            // branches.push(branch);
            // junctions.push(i);
        }
        new_res.push_back(i);
    }
    // for (int i : res) {
    //     while (junctions.front() == i) {
    //         for (auto j : branches.front()) new_res.push_back(j);
    //         branches.pop();
    //         junctions.pop();
    //     }
    //     new_res.push_back(i);
    // }
    new_res.pop_back();
    return new_res;
}

int main() {
    scanf("%d %d", &n, &m);
    for (long long i = 1; i <= m; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        // cout << i << " " << a << " " << b << endl;
        e[a].insert((i << 17) + b);
        e[b].insert((i << 17) + a);
    }
    for (int i = 1; i <= n; i++) {
        if (e[i].size() & 1 or e[1].empty()) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    //
    // find out step count from 1
    //
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : e[x]) {
            int to  = i & mask;
            int e_i = i >> 17;
            if (vis[e_i]) continue;
            vis[e_i] = 1;
            dist[to] = dist[x] + 1;
            q.push(to);
        }
    }
    for (int i = 1; i <= m; i++)
        if (vis[i] == 0) {
            puts("IMPOSSIBLE");
            return 0;
        }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) degree[i] = e[i].size();
    // dfs(1);
    vector<int> res = round_trip(1, 1);
    for (auto i : res) printf("%d ", i);
    puts("1");
}
