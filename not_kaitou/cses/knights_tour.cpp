#include <bits/stdc++.h>
#define SIZE 8
using namespace std;
int res[100], in_d[100];
set<int> in[100], out[100];
 
void print() {
    for (int y = 1; y <= SIZE; y++) {
        for (int x = 1; x <= SIZE; x++) cout << res[x * 10 + y] << " ";
        cout << endl;
    }
}
 
void dfs(int x, int n) {
    res[x] = n;
    if (n == 64) {
        print();
        exit(0);
    }
    vector<pair<int, int>> available_son;
    for (int nx : out[x]) {
        if (res[nx]) continue;
        available_son.push_back(make_pair(--in_d[nx], nx));
        // if (--in_d[nx] == 0) single_in_son.push_back(nx);
    }
    sort(available_son.begin(), available_son.end());
    if (available_son.size() > 1) {
        if (available_son[1].first > 0) {
            if (available_son[0].first == 0)
                dfs(available_son[0].second, n + 1);
            else
                for (auto nx : available_son) dfs(nx.second, n + 1);
        }
    } else if (available_son.size())
        dfs(available_son[0].second, n + 1);
    for (auto nx : available_son) in_d[nx.second]++;
    res[x] = 0;
}
 
int main() {
    int x, y;
    for (x = 1; x <= SIZE; x++)
        for (y = 1; y <= SIZE; y++) {
            int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
            int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
            for (int i = 0; i < 8; i++) {
                int nx = dx[i] + x, ny = dy[i] + y;
                if (nx < 1 or ny < 1) continue;
                if (nx > SIZE or ny > SIZE) continue;
                in[nx * 10 + ny].insert(x * 10 + y);
                out[x * 10 + y].insert(nx * 10 + ny);
                in_d[nx * 10 + ny]++;
            }
        }
    scanf("%d %d", &x, &y);
    dfs(x * 10 + y, 1);
}
