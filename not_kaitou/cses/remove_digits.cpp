#include <iostream>
using namespace std;
int n, f[1123456];
int dfs(int x) {
    if (f[x] or x == 0) return f[x];
    int t = x, res = 1e9;
    while (t) {
        int i = t % 10;
        t /= 10;
        if (i) res = min(res, 1 + dfs(x - i));
    }
    return f[x] = res;
}
int main() {
    cin >> n;
    cout << dfs(n) << endl;
}
