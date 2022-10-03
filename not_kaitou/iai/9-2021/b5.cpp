#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<int> r(2 * b + 5, 0), q;
    int index = 0;
    cout << "0.";
    while (a > 0) {
        int qq = (a << 1) / b;
        a      = (a << 1) % b;
        // if (find(r.begin(), r.end(), a) != r.end()) {
        // int i = find(r.begin(), r.end(), a) - r.begin();
        if (r[b * qq + a] > 0) {
            int i = r[b * qq + a] - 1;
            if (q[i] == qq) {
                for (int j = 0; j < i; j++) cout << q[j];
                cout << "(";
                for (int j = i; j < q.size(); j++) cout << q[j];
                cout << ")";
                return 0;
            }
        }
        q.push_back(qq);
        r[b * qq + a] = q.size();
    }
    for (int i : q) cout << i;
}
