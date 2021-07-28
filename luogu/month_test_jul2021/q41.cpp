#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> a;
    int x;
    // while (cin >> x)
    // {
    //     a.insert(x);
    // }
    set<int> b;
    set<int> res;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (a.find(x) != a.end())
        {
            res.insert(x);
        }
    }
    cout << res.size() << endl;
    for (auto i : res)
    {
        cout << i << " ";
    }

    // set<int> b;
    // for (int i = 0; i < n; i++)
    // {
    //     b.insert(*(a.end() - 1));
    //     a.erase(a.end()-1);
    // }
}