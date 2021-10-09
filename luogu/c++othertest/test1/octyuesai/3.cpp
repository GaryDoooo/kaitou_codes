#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a[n];

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= sum - a[i])
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}