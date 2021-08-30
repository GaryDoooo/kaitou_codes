#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int total = 0, d = 0;
    for (auto i : s)
    {
        // cout << d << endl;
        if (i == 'Y')
        {
            if (d < 5)
                d++;
            total += d;
        }
        if (i == 'N')
            d = 0;
    }
    cout << total << endl;
    return 0;
}