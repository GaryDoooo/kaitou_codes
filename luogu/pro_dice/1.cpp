#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 0, e = 0;
    vector<int> v(3, 0);
    while (cin >> x)
    {
        v[e] = x;
        e++;
    }
    e = 0;
    if (v[0] == 6)
        e++;
    if (v[1] == 6)
        e++;
    if (v[2] == 6)
        e++;
    if (e == 0)
    {
        cout << 0;
        return 0;
    }
    cout << pow(10, e) << endl;
}