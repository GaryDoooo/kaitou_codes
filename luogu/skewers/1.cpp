#include <bits/stdc++.h>
using namespace std;
bool hui(vector<string> &a)
{
    vector<string> r(a.rbegin(), a.rend());
    return (a == r);
}
int main()
{
    vector<string> v = {};
    string i;
    while (cin >> i)
        v.push_back(i);

    int max_x = -1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            vector<string> v2(v.begin() + i, v.begin() + j);
            if (hui(v2))
            {
                if (v2.size() > max_x)
                    max_x = v2.size();
            }
        }
    }
    cout << max_x;
}