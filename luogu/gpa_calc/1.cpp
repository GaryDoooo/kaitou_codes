#include <bits/stdc++.h>
using namespace std;
float roundd(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
int main()
{
    string s;
    cin >> s;
    int jjc = 0;
    float ans = 0;
    for (auto c : s)
    {
        if (c == 'A')
            ans += 4;
        if (c == 'B')
            ans += 3;
        if (c == 'C')
            ans += 2;
        if (c == 'D')
            ans += 1;
        if (c == '-')
        {
            ans -= 0.3;
            jjc++;
        }
        if (c == '+')
        {
            ans += 0.3;
            jjc++;
        }
    }
    ans /= s.size() - jjc;
    // ans = roundd(ans);
    // cout << left << setfill('0') << setw(4) << ans << endl;
    cout << fixed << setprecision(2) << ans;
}