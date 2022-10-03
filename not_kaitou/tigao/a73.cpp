#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> f;
int lb[1505], ub[1505], n, s, p[1505], d;
int main() {
    scanf("%d%d", &n, &s);
    d = trunc((s - 1) / (n - 1));
    for (int i = 0; i < n; i++) {
        lb[i] = i * (d - 1) + 1;
        ub[i] = s - (n - 1 - i) * (d - 1);
        cout << i << ":" << lb[i] << " " << ub[i] << endl;
    }
}
