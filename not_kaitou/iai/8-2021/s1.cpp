#include <bits/stdc++.h>
using namespace std;
int d[2005][2005], la, lb;
string a, b;
int dist(int i, int j) {
    // if (i < 0 and j < 0) return 0;
    if (i < 0 or j < 0) return max(i, j) + 1;
    if (d[i][j] >= 0) return d[i][j];
    char ai = a[i], bj = b[j];
    d[i][j] = min(dist(i - 1, j - 1) + (ai != bj),
                  min(1 + dist(i - 1, j), 1 + dist(i, j - 1)));
    return d[i][j];
}
int main() {
    cin >> a >> b;
    memset(d, 255, sizeof(d));
    la = a.length();
    lb = b.length();
    cout << dist(la - 1, lb - 1) << endl;
    // for (int i = 0; i < lb; i++) {
    //     for (int j = 0; j < la; j++) cout << d[i][j] << " ";
    //     cout << endl;
    // }
}

