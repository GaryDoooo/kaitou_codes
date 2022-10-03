#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> digits;
    for (int i = 0; i < 4; i++)
    {
        digits.push_back(n % 10);
        n /= 10;
    }

    // for (auto i : digits)
    // {
    //     cout << i;
    // }
    // cout << endl;
    // // iter_swap(digits.begin(), digits.begin() + 3);
    // // iter_swap(digits.begin() + 1, digits.begin() + 2);
    // for (auto i : digits)
    // {
    //     cout << i;
    // }
    // cout << endl;

    for (int i = 0; i < 4; i++)
    {
        switch (digits[i])
        {
        case 0:
            digits[i] = 9;
            break;
        case 1:
            digits[i] = 8;
            break;
        case 2:
            digits[i] = 7;
            break;
        case 3:
            digits[i] = 6;
            break;
        case 4:
            digits[i] = 5;
            break;
        case 5:
            digits[i] = 4;
            break;
        case 6:
            digits[i] = 3;
            break;
        case 7:
            digits[i] = 2;
            break;
        case 8:
            digits[i] = 1;
            break;
        case 9:
            digits[i] = 0;
        default:
            break;
        }
    }
    for (auto i : digits)
        cout << i;
    return 0;
}