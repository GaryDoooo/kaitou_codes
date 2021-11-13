#include <iostream>
#include <vector>
using namespace std;
const int N = 10005;
vector<int> e[N];
int n, u, v, x, de[N], cnt[N];
void dfs(int u) {
    cnt[u] = 1;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        de[v] = de[u] + 1;
        dfs(v);
        cnt[u] += cnt[v];
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
    }
    de[1] = 0;
    cnt[0] = 1;
    dfs(1);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << de[x] << " " << cnt[de[x] + 1] << endl;
    }
    return 0;
}