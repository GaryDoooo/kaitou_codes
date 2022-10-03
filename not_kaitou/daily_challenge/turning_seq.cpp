#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    char *s = "NS";
    int res = 0;
    for (int i = 0; i < a.length() - 1; i++) {
        if (a[i] != b[i]) {
            a[i + 1] = s[a[i + 1] == 'N'];
            // b[i + 1] = s[b[i + 1] == 'N'];
            res++;
        }
    }
    // cout << a << endl;
    cout << res;
    return 0;
}