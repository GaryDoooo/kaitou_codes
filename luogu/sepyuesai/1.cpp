#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int mid = (k / 2 + k) * 2;
    int ans = 0;
    if (n > 2 * k)
    {
        ans += 2 * ((n - 2 * k) / k);
        n -= k;
    }
    if (n > mid)
        cout << ans + 4;
    else if (n > k)
        cout << ans + 3;
    else
        cout << ans + 2;
    return 0;
}