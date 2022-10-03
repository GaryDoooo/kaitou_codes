#include <bits/stdc++.h>
using namespace std;
int keys[4096], n, m;
char s[212345];
int main() {
    cin >> n >> m;
    scanf("%s\n", s);
    for (int i = 0; i < m; i++) {
        char c;
        scanf("%c ", &c);
        // cout << c;
        keys[c - 'a'] = 1;
    }
    // for (int i = 0; i < 26; i++) cout << keys[i] << " ";
    unsigned long long cnt = 0;
    unsigned long long res = 0;
    for (int i = 0; i < n; i++) {
        if (keys[s[i] - 'a'] == 1)
            cnt++;
        else {
            res += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    res += cnt * (cnt + 1) / 2;
    cout << res << endl;
}
