#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int e = 1;
    for (int i = 1; i <= n; i++)
    {
        e *= i;
        e %= m;
    }
    cout << e << endl;
    return 0;
}