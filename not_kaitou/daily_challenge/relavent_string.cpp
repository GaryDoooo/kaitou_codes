#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << -1;
    } else {
        int sum = (int)s1[0] + (int)s2[0];
        for (int i = 1; i < s1.length(); i++) {
            if (s1[i] + s2[i] != sum) {
                cout << -1;
                return 0;
            }
        }
        cout << sum - 194;
    }
    return 0;
}