#include <iostream>
using namespace std;
int main()
{
    int n, t;
    cin >> n >> t;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ai = 0, bi = 0, time = 0;
    while (time < t and (ai + bi) < 2 * n)
    {
        if (ai == n)
        {
            time += b[bi++];
            continue;
        }
        if (bi == n)
        {
            time += a[ai++];
            continue;
        }
        if (b[bi] < a[ai])
            time += b[bi++];
        else
            time += a[ai++];
    }
    if (t == time)
        cout << ai + bi;
    else
        cout << ai + bi - 1;
}