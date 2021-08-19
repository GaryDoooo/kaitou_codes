#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n, m;
    cin >> n;
    char *np = (char *)&n;
    char *mp = (char *)&m;
    mp[0] = np[2]; mp[1] = np[3];
    mp[2] = np[0]; mp[3] = np[1];
    cout << m;
}