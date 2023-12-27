#include <bits/stdc++.h>
using namespace std;
 
int n, m, e_cnt, e_head[505], in_path[505], done[505];
struct edge {
    int to, nxt;
    long long weight, orig_weight;
};
edge e[14005];
long long res;
 
void add_edge(int a, int b, int c) {
    if ((b == 1) or (a == n)) return;
    for (int i = e_head[a]; i; i = e[i].nxt)
        if (e[i].to == b) {
            e[i].weight += c;
            e[i].orig_weight += c;
            return;
        }
    e[++e_cnt] = {b, e_head[a], c, c};
    e_head[a]  = e_cnt;
}
 
long long input(int node, long long data, int back_trace) {
    if (node == n) {
        res += data;
        return 0;
    }
    in_path[node] = 1;
    for (int i = e_head[node]; i; i = e[i].nxt) {
        if (in_path[e[i].to] or e[i].weight == 0 or done[e[i].to]) continue;
        long long data_input = min(data, (long long)e[i].weight);
        long long data_left  = input(e[i].to, data_input, back_trace);
        if (data_left)
            e[i].weight = 0;
        else
            e[i].weight -= (data_input - data_left);
        data -= (data_input - data_left);
        if (back_trace) add_edge(e[i].to, node, data_input - data_left);
        if (data <= 0) break;
    }
    in_path[node] = 0;
    return max(0LL, data);
}
 
int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
    }
    input(1, 1e18, 0);
    long long res0 = res;
    res            = 0;
    for (int i = 1; i <= e_cnt; i++) e[i].weight = e[i].orig_weight;
    input(1, 1e18, 1);
    cout << max(res, res0) << endl;
}
