#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int len;
    cin >> len;
    vector<int> v;
    int temp;
    for (int i = 0; i < len; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    long long min_diff = -1;
    for (int i = 0; i < len; i++)
    {
        long long l_sum = 0;
        long long r_sum = 0;

        for (int j = 0; j < i; j++)
        {
            l_sum += v[j] * (i - j);
        }
        for (int j = 0; j < len - i; j++)
        {
            r_sum += v[j + i] * j;
        }

        long long diff = abs(r_sum - l_sum);
        if (diff < min_diff or min_diff < 0)
        {
            min_diff = diff;
        }
    }
    cout << min_diff;
}