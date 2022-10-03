#include <bits/stdc++.h>
using namespace std;
// bool hui(string a)
// {
//     string b = a;
//     reverse(b.begin(), b.end());
//     return (a == b);
// }
int main()
{
    long long n;
    cin >> n;
    unsigned long long ans = 0;
    // int x = stoi(n);
    // int c = 0;
    // int i = 0;
    // while (c < n)
    // {
    //     i++;
    //     // string s = to_string(i);
    //     // if (s.length() % 2 == 1)
    //     //     continue;
    //     // if ((int)log10(i) % 2 == 0)
    //     // continue;
    //     // if (i>99 and i<1000) continue;
    //     // if (to_string(i).length() % 2 == 0)
    //     if (hui(s))
    //     {
    //         ans += i;
    //         c++;
    //     }
    // }
    string s;
    for (int i = 1; i <= n; i++)
    {
        s = to_string(i);
        string e(s.rbegin(), s.rend()); // = s;
        s += e;
        ans += stol(s, nullptr, 10);
    }
    cout << ans << endl;
    return 0;
}