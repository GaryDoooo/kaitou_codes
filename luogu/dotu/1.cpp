#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[2010];
int dotu(string s)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        a[i] = s[i] - 'a';
    }
    while (len > 1)
    {
        for (int i = 0; i < len; i++)
        {
            a[i] = (a[i] + a[i + 1]) % 10;
        }
        len--;
    }
    return a[1];
}

int main()
{
    string s, e;
    cin >> s >> e;
    cout << max(dotu(s + e), dotu(s + e));
    return 0;
}
