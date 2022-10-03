#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to, prev, w;
};
edge e[4005];
int head[1005], n, m, K, a, b, l;
vector<int> weights;
bool check(int res) {
    int in_q[1005], cnt[1005];
    memset(in_q, 0, sizeof(in_q));
    memset(cnt, 127, sizeof(cnt));
    in_q[1] = 1;
    cnt[1]  = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        in_q[now] = 0;
        for (int i = head[now]; i; i = e[i].prev) {
            if (cnt[e[i].to] > cnt[now] + (e[i].w > res)) {
                cnt[e[i].to] = cnt[now] + (e[i].w > res);
                if (in_q[e[i].to]) continue;
                q.push(e[i].to);
                in_q[e[i].to] = 1;
            }
        }
    }
    // for (int i = 0; i <= n; i++) cout << cnt[i] << " ";
    // cout << endl;
    if (cnt[n] > 1e9) {
        puts("-1");
        exit(0);
    }
    return cnt[n] <= K;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int edge_cnt = 1; edge_cnt <= m * 2; edge_cnt++) {
        scanf("%d%d%d", &a, &b, &l);
        weights.push_back(l);
        e[edge_cnt].prev = head[a];
        head[a]          = edge_cnt;
        e[edge_cnt].to   = b;
        e[edge_cnt].w    = l;
        swap(a, b);
        edge_cnt++;
        e[edge_cnt].prev = head[a];
        head[a]          = edge_cnt;
        e[edge_cnt].to   = b;
        e[edge_cnt].w    = l;
    }
    sort(weights.begin(), weights.end());
    if (m <= K) {
        if (check(2e9))
            puts("0");
        else
            puts("-1");
        return 0;
    }
    int left = 0, right = weights[m - K - 1];
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", right);
}
// int res = 2e9, in_q[1005];
// queue<int> q;
// struct path{
//     int in[1005];
//     multiset<int> l;
// };
// vector<path>  p[1005];
