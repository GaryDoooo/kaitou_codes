#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("cowfind.in", "r", stdin);
    freopen("cowfind.out", "w", stdout);
    // fstream in_file;
    // in_file.open("cowfind.in", ios::out);
    // fstream out_file;
    // out_file.open("cowfind.out", ios::out);
    string s = "";
    cin >> s;
    int ans = 0;
    int e = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == ')' and s[i] == ')')
        {
            ans += e;
        }
        else if (s[i - 1] == '(' and s[i] == '(')
        {
            e++;
        }
    }
    cout << ans;
    return 0;
}