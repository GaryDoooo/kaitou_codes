#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[100005];
    long long mid, sum;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    if (n % 2 == 0)
    {
        mid = (a[n / 2] + a[n / 2 + 1]) / 2;
    }
    else
    {
        mid = a[n / 2 + 1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > mid)
        {
            sum += a[i] - mid;
        }
        else
        {
            sum += mid - a[i];
        }
    }

    cout << sum;
    return 0;
}
