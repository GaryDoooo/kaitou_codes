#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int miny = 2021, mind = 32, minm = 13;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int y, m, d;
        y = stoi(s.substr(0, 4));
        m = stoi(s.substr(5, 2));
        d = stoi(s.substr(8, 2));
        if (y < miny)
        {
            miny = y;
            minm = m;
            mind = d;
        }
        if (y == miny)
        {
            if (m < minm)
            {
                miny = y;
                minm = m;
                mind = d;
            }
            if (m == minm)
            {
                if (d < mind)
                {
                    miny = y;
                    minm = m;
                    mind = d;
                }
            }
        }
    }
    printf("%04d-%02d-%02d", miny, minm, mind);
    return 0;
}