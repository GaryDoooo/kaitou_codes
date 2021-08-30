#include <bits/stdc++.h>
using namespace std;
int main()
{
    string layer;
    cin >> layer;
    int sum_of_layer = 0;
    // string layer = s;
    while (layer.size() > 1)
    {
        sum_of_layer = 0;
        for (char i : layer)
        {
            sum_of_layer += i - '0';
        }
        layer = to_string(sum_of_layer);
    }
    cout << layer;
    return 0;
}