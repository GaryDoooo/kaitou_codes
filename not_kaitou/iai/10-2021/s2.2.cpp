#include <bits/stdc++.h>
using namespace std;
long long res = 0;
vector<int> son[100001];
int v[100001];
void traversal(int node, long long inherit) {
    res += abs(v[node] + inherit);
    long long new_inherit = inherit - (inherit + v[node]);
    for (int i : son[node]) {
        traversal(i, new_inherit);
    }
}
int main() {
    int n = read();
    for (int i = 2; i <= n; i++) {
        int input = read();
        son[input].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        v[i] = read();
    }
    traversal(1, 0);
    cout << res;
}
