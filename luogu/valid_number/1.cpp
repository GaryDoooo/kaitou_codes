#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s[0] == '+' || s[0] == '-')
        s = s.substr(1);
    if (s == ".")
    {
        cout << "Invalid";
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            cnt++;
            if (cnt > 1)
            {
                cout << "Invalid";
                return 0;
            }
        }
        else if (s[i] < '0' || s[i] > '9')
        {
            cout << "Invalid";
            return 0;
        }
    }
    cout << "Valid";
    return 0;
}