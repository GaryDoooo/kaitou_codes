#include <bits/stdc++.h>
using namespace std;
map<int, int> m[2505];
int n, e_cnt, s, t, st, tt, lt, done[2505];
struct node {
    int len, s;
};
struct cmp {
    bool operator()(const node& a, const node& b) { return a.len > b.len; }
};
priority_queue<node, vector<node>, cmp> q;

int main() {
    scanf("%d%d%d%d", &n, &e_cnt, &st, &tt);
    if (st == tt) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < e_cnt; i++) {
        scanf("%d%d%d", &s, &t, &lt);
        // if (tt<st) swap(st, tt);
        if (m[s][t] == 0)
            m[s][t] = lt;
        else
            m[s][t] = min(m[s][t], lt);
        swap(s, t);
        if (m[s][t] == 0)
            m[s][t] = lt;
        else
            m[s][t] = min(m[s][t], lt);
    }
    // for (auto i : m[5]) cout << i.first << " " << i.second << endl;
    q.push({0, st});
    while (!q.empty()) {
        node now    = q.top();
        done[now.s] = 1;
        // cout << now.s << endl;
        q.pop();
        if (now.s == tt) {
            printf("%d\n", now.len);
            return 0;
        }
        for (auto dest : m[now.s]) {
            if (done[dest.first]) continue;
            q.push({dest.second + now.len, dest.first});
        }
    }
}
