#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n > 1000 and n % 500 == 0)
        cout << (n - 1000) / 500 * 5 + 12;
    else if (n > 1000)
        cout << 12 + ((n - 1000) / 500 + 1) * 5;
    else
        cout << 12;
}