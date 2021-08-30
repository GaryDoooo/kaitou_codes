#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "";
    string e;
    while (cin >> e)
    {
        s += e;
        s += " ";
    }
    int ans = 0;
    vector<int> v = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    for (int i = 0; i < s.length() - 1; i++)
    {
        char c = s[i];
        if (c != ' ')
            ans += v[c - 'a'];
        else
            ans++;
    }
    cout << ans << endl;
    return 0;
}