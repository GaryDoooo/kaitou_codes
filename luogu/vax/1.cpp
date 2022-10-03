#include <bits/stdc++.h>
using namespace std;
int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    string s;
    cin >> s;
    string delim = "-";
    vector<string> dates = {};
    vector<int> d = {};

    auto start = 0U;
    auto end = s.find(delim);
    while (end != string::npos)
    {
        dates.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }

    for (int i = 0; i < dates.size(); i++)
    {
        d.push_back(stoi(dates[i]));
    }
    for (auto i : d)
        cout << i << " ";
    vector<int> d2(d.begin(), d.end());

    if (d[2] + 14 > m[d[1]])
    {
        if (d[1] + 1 > 12)
        {
            d2[1] = 1;
            d2[0] += 1;
        }
        else
        {
            d2[1] += 1;
        }
        d2[2] += (d[2] + 14 - m[d[1]]);
    }
    else
    {
        d2[2] = d[2] + 14;
    }
    cout << d2[0] << "-" << d2[1] << "-" << d2[2];
    return 0;
}