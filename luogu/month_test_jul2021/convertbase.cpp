#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> dec_to_base(int n, int base)
{
    vector<int> res;
    while (n >= 1)
    {
        res.push_back(n % base);
        n /= base;
    }
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    vector<int> res2(res.rbegin(), res.rend());

    return res2;
}
int base_to_dec(vector<int> n, int base)
{
    int res = 0;
    int pow = 1;
    while (n.size() > 0)
    {
        int l = n.back();
        n.pop_back();
        res += l * pow;
        pow *= base;
    }

    return res;
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

string digit_to_string(vector<int> d)
{
    string res = "";
    for (int i = 0; i < d.size(); i++)
    {
        char e = d[i];
        if (d[i] < 10)
            e += 48;
        else
            e += 55;
        res += e;
    }
    return res;
}

int main()
{
    string n;
    int og_base, new_base;
    cin >> og_base >> new_base >> n;
    vector<int> digits = string_to_digit(n);
    // for (auto i : digits)
    //     cout << i << " ";
    // cout << endl;
    n = digit_to_string(digits);
    // cout << n;
    int dec = base_to_dec(digits, og_base);
    vector<int> res = dec_to_base(dec, new_base);
    string fin = digit_to_string(res);
    cout << fin << endl;
    return 0;
}