#include <bits/stdc++.h>
using namespace std;
int main()
{
    int startb, c_for_b, eb_for_b;
    cin >> startb >> c_for_b >> eb_for_b;
    cout << startb + (startb / c_for_b) + (startb / eb_for_b) << endl;
    return 0;
}