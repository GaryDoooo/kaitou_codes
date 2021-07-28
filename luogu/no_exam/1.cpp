#include <iostream>
using namespace std;
int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int res = 0, an = 1, bn = 1, cn = 1, e = 0;
    for (int i = 0; i < n; i++)
    {
        e = 0;
        if (an == a)
        {
            an = 1;
            e++;
        }
        else
            an++;
        if (bn == b)
        {
            bn = 1;
            e++;
        }
        else
            bn++;
        if (cn == c)
        {
            cn = 1;
            e++;
        }
        else
            cn++;

        if (e == 0)
            res++;
    }
    cout << res << endl; //
    return 0;
}