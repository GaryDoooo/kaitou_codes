#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//
// 上面这一套在CSES好像没什么用
//
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int maxn      = 5e2;
const long long inf = (long long)1e18;
long long fw[1 << 18];
int n, m, q;

int main() {
    cin >> n >> m >> q;
    fill(fw, fw + (1 << 18), inf);
    for (int i = 0; i < n; i++) {
        fw[(i << 9) + i] = 0;  // A faster way to make 2D array
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        fw[(v << 9) + u] = fw[(u << 9) + v] =
            min(fw[(u << 9) + v], (long long)w);
    }
    for (int k = 0; k < n; k++) {
        //
        // Have the mid point in the first loop. Only works it is in the first
        // loop.
        // 相当于把这个k点去掉也不影响其他点的距离。再想想为什么k必须在第一个。
        //
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fw[(i << 9) + j] =
                    min(fw[(i << 9) + j], fw[(i << 9) + k] + fw[(k << 9) + j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << (fw[(u << 9) + v] == inf ? -1 : fw[(u << 9) + v]) << endl;
    }
}
