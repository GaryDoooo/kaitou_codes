#include <bits/stdc++.h>
using namespace std;
int c[30];
int main()
{
    freopen("char.in", "r", stdin);
    freopen("char.out", "w", stdout);
    memset(c, 128, sizeof(c));
    string s;
    cin >> s;
    int ansx = 1e9;
    for (int i = 0; i < s.length(); i++){
        int posc = s[i]-'a';
        ansx = min(ansx, i-c[posc]);
        c[posc] = i;
    }
    int ansy = -1;
    for (int i = 0; i < s.length(); i++){
        int posc = s[i]-'a';
        ansy = max(ansy, abs(i-c[posc]));
    }
    if (ansy == -1 or ansx == 1e9) cout << -1;
    else cout << ansx << " " << ansy;
    return 0;
}
