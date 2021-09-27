#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    __int128 dec = 0;
    for (int i = 0; i < s.length(); i++) {
        // int digit;
        if (s[i] >= '0' && s[i] <= '9')
            dec = dec * a + (__int128)(s[i] - '0');
        else
            dec = dec * a + (__int128)(s[i] - 'a' + 10);
    }
    vector<int> res;
    cout << "(";
    if (dec == 0) cout << 0;
    while (dec > 0) {
        res.push_back((int)dec % b);
        dec /= b;
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        char c;
        if (res[i] < 10)
            c = (char)res[i] + '0';
        else
            c = (char)res[i] - 10 + 'a';
        cout << c;
    }
    cout << ")";
    cout << b;
}

