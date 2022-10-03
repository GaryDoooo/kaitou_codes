#include <iostream>
#include <algorithm>
using namespace std;
struct Point
{
    int x = 0, y = 0;
};

bool cmp(Point a, Point b)
{
    return (a.x < b.x or (a.x == b.x and a.y < b.y));
}
int main()
{
    int n;
    cin >> n;
    Point a[10010];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, cmp);

    int xx = -1;
    for (int i = 0; i < n; i++)
    {
        // cin >> x >> y;
        if (a[i].x != xx)
        {
            cout << a[i].x << " " << a[i].y << endl;
            xx = a[i].x;
        }
    }

    return 0;
}