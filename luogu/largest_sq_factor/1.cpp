#include <bits/stdc++.h>
using namespace std;
vector<int> getDivisors(int n)
{
    vector<int> res = {};
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            res.push_back(i);
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> d = getDivisors(n);
    int maxx = -1;
    for (auto i : d)
    {
        int s = sqrt(i);
        if (s * s == i)
        {
            if (i > maxx)
                maxx = i;
        }
    }
    cout << maxx << endl;
    return 0;
}