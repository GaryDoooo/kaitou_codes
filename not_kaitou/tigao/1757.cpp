#include <bits/stdc++.h>
using namespace std;
struct node {
    int res = -1e9;
    vector<int> a;
};
node a[15][15];

node find_max(int n, int k) {
    node res;
    if (n <= 0 or k <= 0) return res;
    if (a[n][k].res >= 0) return a[n][k];
    if (k == 1) {
        res.a.push_back(1);
        res.res        = n;
        return a[n][k] = res;
    }
    if (n == 1) {
        res.res = k;
        for (int i = 1; i <= k; i++) res.a.push_back(i);
        return a[n][k] = res;
    }
    for (int i = 1; n - i + 1 > 0; i++) {
        // if (n - i + 1 <= 0) break;
        node temp = find_max(n - i + 1, k - 1);
        // int acheivable =0,j;
        // for (j =temp.res+1;j>0;j--)
        //     acheivable=max(acheivable,
        //             j*(temp.res+1-j+1)
        int acheivable = (temp.res + 1) * i + temp.res - 1;
        if (acheivable > res.res) {
            res.res = acheivable;
            res.a   = temp.a;
            res.a.push_back(temp.res + 1);
        }
    }
    return a[n][k] = res;
}

int main() {
    int n, k;
    cin >> n >> k;
    node res = find_max(n, k);
    for (int i : res.a) {
        cout << i << " ";
    }
    cout << endl << "MAX=" << res.res << endl;
}
