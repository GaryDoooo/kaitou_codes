#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, open_time;
    cin >> n >> open_time;
    int total_open_time = 0, open_time_counter = open_time;

    int times[n];
    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (times[i] - times[i - 1] > open_time)
        {
            total_open_time += open_time;
        }
        else
        {
            total_open_time += (times[i] - times[i - 1]);
        }
    }
    cout << total_open_time;
    return 0;
}