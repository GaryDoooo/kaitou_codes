#include <bits/stdc++.h>
using namespace std;
int start, finish;

int rec(int a)
{
    // cout << a << " " << (a == start) << endl;
    if (a == start)
        return 0;
    if (a < start)
        return 1000000000;
    if (a < start * 2)
        return a - start;
    int div = 1000000000, add;
    if (a % 2 == 0)
    {
        div = rec(a / 2);
        return div + 1;
    }
    else
    {
        add = rec((--a) / 2);
        return add + 2;
    }
    // return (min(div, add)) + 1;
}
int main()
{
    // int start, finish;
    cin >> start >> finish;
    // int i = finish;
    // int ans = 0;
    // while (i > start)
    // {
    //     if (i % 2 == 0)
    //         i /= 2;
    //     else
    //         i--;
    //     ans++;
    // }
    // cout << ans << endl;
    cout << rec(finish) << endl;
    return 0;
}