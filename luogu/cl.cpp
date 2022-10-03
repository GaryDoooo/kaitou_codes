#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a >= 90 and b >= 90) or (a >= 90 and c >= 90) or (b >= 90 and c >= 90))
    {
        if (d >= 85)
        {
            cout << "Qualified";
            return 0;
        }
    }
    cout << "Not qualified";
}