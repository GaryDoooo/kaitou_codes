#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000009], minn = 1000000, maxn = -1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i] - minn);
    }
    cout << maxn;
    return 0;
}