#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, minn = 100005, maxn = -1;
    cin >> n >> m;
    int a[n + 5];
    a[0] = 100005;
    // a[0] = 0;
    int cm = m;
    int ch = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cm += a[i - 1] * ch;
        ch = 0;
        // cout << a[i - 1] << " " << a[i] << endl;
        if (a[i - 1] < a[i])
        {
            ch += cm / a[i - 1];
            cm -= a[i - 1] * ch;
        }
        // cout << cm << " " << ch << endl;
    }
    cm += a[n] * ch;
    ch = 0;
    cout << cm << endl;
    return 0;
}