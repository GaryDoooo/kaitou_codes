#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        cout << name << " ";
        int k, total = 0;
        cnt = 0;
        for (int j = 0; j < m; j++) {
            cin >> k;
            if (k > 0) {
                cnt++;
                total += k + cnt - 1; //(cnt > 1) + (cnt > 2);
            } else {
                cnt = 0;
            }
        }
        cout << total << endl;
    }
    return 0;
}