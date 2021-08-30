#include <bits/stdc++.h>
using namespace std;
int main()
{
    //stack<int> s;
    vector<int> s(0);
    int n;
    cin >> n;
    int o[n + 2];
    // o[2] = 0;
    unsigned int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        //cout << x << " ";
        o[i] = x;
    }
    int e = 0;
    int i = 1;
    int out_index = 1;
    //   cout << i << " ";
    // for (int i : o)
    //     cout << i << " ";
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        s.push_back(i);
        while (s[s.size() - 1] == o[out_index] and out_index <= n)
        {
            s.pop_back();
            out_index++;
        }
        // cout << s.size() << endl;
        // for (int ii : s)
        //     cout << ii << " ";
        // cout << endl;
        // cout << i << " " << e << endl;
    }

    if (s.size() == 0)
        cout << "Valid";
    else
        cout << "Invalid";
    return 0;
}