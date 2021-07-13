#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int x;
    while (cin >> x)
    {
        a.push_back(x);
    }
    vector<int> res;
    // for (auto i : a)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= k; i++)
    // {
    //     if (count(a.begin(), a.end(), i) == 2)
    //     {
    //         res.push_back(i);
    //     }
    // }
    // cout << res.size() << endl;

    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        b.push_back(a.back());
        a.pop_back();
    }
    // for (auto i : b)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto i : a)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    sort(b.begin(), b.end());
    for (auto i : a)
    {
        if (*(lower_bound(b.begin(), b.end(), i)) == i)
        {
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto i : res)
    {
        cout << i << " ";
    }
}