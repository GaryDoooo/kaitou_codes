#include <bits/stdc++.h>
using namespace std;
int n, t;
bool rec(int s[], int sum, int i)
{

    if (sum == t)
        return true;
    if (i == n)
        return false;
    // cout << i << " " << sum << " " << endl;
    int si = s[i];
    return rec(s, sum + si, i + 1) or rec(s, sum, i + 1);
}
int main()
{
    cin >> n >> t;
    int s[n];
    //cout << sizeof(s) / sizeof(s[0]) << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    if (rec(s, 0, 0))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}