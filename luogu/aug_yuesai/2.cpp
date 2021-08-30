#include <bits/stdc++.h>
using namespace std;
map<char, int> ro_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};
int ro_to_int(string ro)
{
    vector<int> ans;
    for (int i = 0; i < ro.length(); i++)
    {
        ans.push_back(ro_int[ro[i]]);
    }
    int val, prev_val;
    for (int i = 1; i < ans.size(); i++)
    {
        val = ans[i];
        prev_val = ans[i - 1];
        if (val > prev_val)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (ans[j] > ans[j + 1])
                {
                    break;
                }
                ans[j] = abs(ans[j]) * -1;
            }
        }
    }
    int res = 0;
    for (auto i : ans)
    {
        res += i;
    }
    return res;
}
vector<vector<string>> itr = {
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, //ones
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, //tens
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, //HUNDREDS
    {"", "M", "MM", "MMM"}                                        // thousands
};
string int_to_ro(int n)
{
    string res = "";

    if (n >= 1000)
    {
        res += itr[3][n % 10000 / 1000];
    }
    if (n >= 100)
    {
        res += itr[2][n % 1000 / 100];
    }
    if (n >= 10)
    {
        res += itr[1][n % 100 / 10];
    }
    res += itr[0][n % 10];

    return res;
}
int main()
{
    //////// ro to int
    // string ro;
    // cin >> ro;
    // cout << ro_to_int(ro) << endl;
    /////// int to ro
    int n;
    cin >> n;
    cout << int_to_ro(n) << endl;
    return 0;
}