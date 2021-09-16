#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) { ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;// * f;
}
int main() {
    int n = read(), m = read();//, temp;
    vector<int> odd[m + 1], even[m + 1];
    int a[n + 1];
    for (register int i = 1; i <= n; i++) a[i] = read();
    for (register int i = 1; i <= n; i++) {
        if (i & 1)
            odd[read()].push_back(i);
        else
            even[read()].push_back(i);
    }
    // cout << n << endl;
    int res = 0;
    for (register int i = 1; i <= m; i++) {
        // https://www.acwing.com/file_system/file/content/whole/index/content/1340605/
        int sum_xiwi = 0, sum_xi = 0, sum_wi = 0;
        for (register int j = 0; j < odd[i].size(); j++) {
            sum_xi = (sum_xi + odd[i][j]) % 10007;
            sum_wi = (sum_wi + a[odd[i][j]]) % 10007;
            sum_xiwi = (sum_xiwi + ((long long)odd[i][j] * (long long)a[odd[i][j]]) % 10007) % 10007;
        }
        res = (res + (odd[i].size() - 2) * sum_xiwi + ((long long)sum_xi * (long long)sum_wi) % 10007) % 10007;
        sum_xiwi = 0, sum_xi = 0, sum_wi = 0;
        for (register int j = 0; j < even[i].size(); j++) {
            sum_xi = (sum_xi + even[i][j]) % 10007;
            sum_wi = (sum_wi + a[even[i][j]]) % 10007;
            sum_xiwi = (sum_xiwi + ((long long)even[i][j] * (long long)a[even[i][j]]) % 10007) % 10007;
        }
        res = (res + (even[i].size() - 2) * sum_xiwi + ((long long)sum_xi * (long long)sum_wi) % 10007) % 10007;
    }
    cout << res;
}