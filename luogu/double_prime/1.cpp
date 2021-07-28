#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0 or n < 2)
        return false;
    for (int i = 3; i < sqrt(n) + 1; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> string_to_digit(string s)
{
    vector<int> res;
    for (int i = 0; i < s.length(); i++)
    {
        char e = s[i];
        if (e >= 48 and e <= 57)
            res.push_back(e - 48);
        if (e >= 65)
            res.push_back(e - 55);
    }
    return res;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int l;
    bool n = true;
    for (int i = a; i <= b; i++)
    {
        // string s = to_string(i);
        // // vector<int> d = string_to_digit(s);

        // for (auto e : s)
        // {
        //     if (e == '1')
        //         continue;
        //     if (!is_prime(e - 48))
        //         continue;
        // }

        // cout << s.substr(0, s.length() / 2) << " " << s.substr(s.length() / 2) << endl;
        // if (!(s.substr(0, s.length() / 2) == s.substr(s.length() / 2)))
        //     continue;

        if (is_prime(i))
        {
            l = i / 10;
            if (is_prime(l))
            {
                cout << i << endl;
                n = false;
            }
        }
    }
    if (n)
        cout << "None";
}