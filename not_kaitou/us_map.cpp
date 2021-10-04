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
int n, a[100], c[100] = {0}, res = MAX_INT, c_res[100];
usint v[100];
void check() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] * c[i];
    }
    if (sum < res) {
        res = sum;
        memcpy(c_res, c, sizeof(c_res));
    }
}
void dfs(int x) {
    if (x > n)
        check();
    else {
        usint color{1, 2, 3, 4};
        for (int i : v[x]) color.erase(c[i]);
        for (int i : color) {
            c[x] = i;
            dfs(x + 1);
        }
        c[x] = 0;
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
    dfs(1);
    cout << "Res = " << res << endl;
    for (int i = 1; i <= n; i++) cout << i << "=" << c_res[i] << " ";
    cout << endl;
}
