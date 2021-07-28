#include <iostream>
using namespace std;
long long diff[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
    }
    for (auto i : diff)
        cout << diff[i] << " ";
}