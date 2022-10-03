#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1][6];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < (n); j++)
        {
            int e;
            cin >> e;
            a[e][5] = e;
            a[e][i] = j;
        }
    }
    sort(a, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i][5] << " ";
    }
    return 0;
}