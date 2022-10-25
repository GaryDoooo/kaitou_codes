/*
 
 这种到最后一个点的最大值，最小值的问题，可以倒着做，用DFS DP
 需求这个图没有环 

int dfs(int u) {
    if (dp[u] != -2) return dp[u]; 
    int &ret = dp[u]; 直接定义指针，后面就简单
    if (u == 1) return ret = 1;
    ret = -1; 入度为零的点
    接下来看每个父节点哪个最大
    for (int i = head[u]; i; i = nxt[i]) {
        int t = dfs(pnt[i]);
        if (t != -1 && t + 1 > ret) {
            ret = t + 1;
            pre[u] = pnt[i];
        }
    }
    return ret;
}
 */


#include <bits/stdc++.h>
template <typename Tp>
inline void read(Tp& x) {
    x = 0; bool fg = 0; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') fg ^= 1; ch = getchar();}
    while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (Tp)(ch ^ 48), ch = getchar();
    if (fg) x = -x;
}
template <typename Tp, typename... Args>
void read(Tp& t, Args& ...args) { read(t); read(args...); }
using namespace std;
typedef long long ll;
const int N = 100010;
const int M = 200010;
int head[N], pnt[M], nxt[M], E;
int dp[N], pre[N], n, m;
void adde(int u, int v) {
    E++; pnt[E] = v; nxt[E] = head[u]; head[u] = E;
}
int dfs(int u) {
    if (dp[u] != -2) return dp[u];
    int &ret = dp[u];
    if (u == 1) return ret = 1;
    ret = -1;
    for (int i = head[u]; i; i = nxt[i]) {
        int t = dfs(pnt[i]);
        if (t != -1 && t + 1 > ret) {
            ret = t + 1;
            pre[u] = pnt[i];
        }
    }
    return ret;
}
int main() {
    read(n, m);
    for (int i = 1; i <= m; ++i) {
        int u, v; read(u, v);
        adde(v, u);
    }
    for (int i = 1; i <= n; ++i) dp[i] = -2;
    int ans = dfs(n);
    if (ans == -1) puts("IMPOSSIBLE");
    else {
        printf("%d\n", ans);
        vector<int> a;
        for (int x = n; x; x = pre[x]) {
            a.push_back(x);
        }
        reverse(a.begin(), a.end());
        for (int i : a) printf("%d ", i);
        puts("");
    }
    return 0;
}
