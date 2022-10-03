#include <algorithm>
#include <iostream>
using namespace std;
struct Line
{
    int s, e;
};
bool cmp(Line a, Line b)
{
    return (a.e < b.e);
}
int main()
{
    int seg, n, ans = 0;
    Line a[n + 1];
    cin >> seg >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].e;
    }
    sort(a + 1, a + n, cmp);
    bool planted[n];
    for (int i = 1; i <= n; i++)
    {
        int t = 0;
        for (int j = a[i].s; j <= a[i].e; j++)
        {
            if (planted[j])
                t++;
        }
        if (t > 0)
            continue;
        else
        {
            planted[a[i].e] = 1;
            ans++;
        }
    }
    cout << ans;
    return 0;
}