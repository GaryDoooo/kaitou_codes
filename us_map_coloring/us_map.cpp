#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
////////////////////////
int n, a[100], c[100] = {0}, res = MAX_INT, c_res[100], cnt = 0, seq[100];
usint v[100];
void dfs(int x, int cost) {
    if (cost >= res) return;
    if (x >= n) {
        cout << ++cnt << "\t" << cost << endl;
        res = cost;
        memcpy(c_res, c, sizeof(c_res));
    } else {
        int idx = seq[x];
        usint color{1, 2, 3, 4};
        for (int i : v[idx]) color.erase(c[i]);
        for (int i : color) {
            c[idx] = i;
            dfs(x + 1, cost + a[idx] * i);
        }
        c[idx] = 0;
    }
}
int main() {
    n     = read();
    int m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 0; i < m; i++) {
        int u = read(), e = read();
        v[u].insert(e);
        v[e].insert(u);
    }
    int neigbors_cnt[n + 1], done[n + 1], pick, max_neighbors = 0;
    memset(neigbors_cnt, 0, sizeof(neigbors_cnt));
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++) {
        if (v[i].size() > max_neighbors) {
            max_neighbors = v[i].size();
            pick          = i;
        }
    }
    seq[0]     = pick;
    done[pick] = 1;
    for (int i : v[pick]) neigbors_cnt[i]++;
    for (int seq_i = 1; seq_i <= n; seq_i++) {
        max_neighbors = -1;
        for (int k = 1; k <= n; k++) {
            if (neigbors_cnt[k] > max_neighbors and done[k] == 0) {
                pick          = k;
                max_neighbors = neigbors_cnt[k];
            }
        }
        done[pick] = 1;
        seq[seq_i] = pick;
        for (int k : v[pick]) neigbors_cnt[k]++;
    }
    cout << "done reading" << endl;
    dfs(0, 0);
    cout << "Res = " << res << endl;
    for (int i = 1; i <= n; i++) cout << i << "=" << c_res[i] << " ";
    cout << endl;
}
