#include <bits/stdc++.h>
using namespace std;
int main()
{
    string e;
    cin >> e;
    const string s = "black";
    const string t = "block";

    std::string::size_type n = 0;
    while ((n = e.find(s, n)) != std::string::npos)
    {
        e.replace(n, s.size(), t);
        n += t.size();
    }

    cout << e;
    return 0;
}