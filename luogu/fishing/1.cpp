#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 5 <= 3 and n % 5 != 0)
        cout << "Fishing";
    else
        cout << "Lying";
    return 0;
}