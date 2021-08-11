#include <bits/stdc++.h>
using namespace std;
int main() {
    set<int> first_lvl, second_lvl;
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for (	int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        if (a[i] == 1 and b[i] != 1) first_lvl.insert(b[i]);
        if (b[i] == 1 and a[i] != 1) first_lvl.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        bool a_first_lvl = first_lvl.find(a[i]) != first_lvl.end();
        bool b_first_lvl = first_lvl.find(b[i]) != first_lvl.end();
        if (a_first_lvl or b_first_lvl) {
            if (not a_first_lvl) second_lvl.insert(a[i]);
            if (not b_first_lvl) second_lvl.insert(b[i]);
        }
    }
    for (auto i : first_lvl) cout << i << " ";
    cout << endl;
    for (auto i : second_lvl) if (i != 1) cout << i << " ";
    return 0;
}