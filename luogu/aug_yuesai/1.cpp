#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b)
    {
        cout << "0";
        return 0;
    }
    if (y >= x)
    {
        cout << "Impossible";
        return 0;
    }
    int result = (b - a) / (x - y);
    if ((b - a) % (x - y) == 0)
        cout << result + 1;
    else
        cout << result;
    return 0;
}