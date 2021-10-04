#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0 or n < 2)
        return false;
    for (int i = 3; i < sqrt(n) + 1; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    long long n;
    cin >> n;
    while (1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else if (n % 3 == 0)
        {
            n /= 3;
        }
        else if (n % 5 == 0)
        {
            n /= 5;
        }
        else
        {
            break;
        }
    }
    if (n != 1)
        cout << "Irregular Number" << endl;
    else
        cout << "Regular Number" << endl;
    return 0;
}