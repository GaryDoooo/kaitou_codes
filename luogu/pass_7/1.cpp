#include <bits/stdc++.h>
using namespace std;
int main()
{
    int start, finish;
    cin >> start >> finish;
    // bool has7 = false;
    for (int i = start; i <= finish; i++)
    {
        // has7 = false;
        if (i % 7 == 0)
        {
            cout << "pass" << endl;
            continue;
        }
        // string s = to_string(i);
        // for (char c : s)
        // {
        //     if (c == '7')
        //     {
        //         has7 = true;
        //         cout << "pass" << endl;
        //         break;
        //     }
        // }
        // if (!has7)
        if (i % 10 == 7)
            continue;
        cout << i << endl;
    }
    return 0;
}