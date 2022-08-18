#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long m;
    cin >> m;
    if (m == 2)
        cout << "T";
    else if (m < 2)
        cout << "F";
    else if (m & 1) {
        for (unsigned long long i = 3; i <= sqrt(m); i += 2) {
            if (m % i == 0) {
                cout << "F";
                return 0;
            }
        }
        cout << "T";
    } else
        cout << "F";
    return 0;
}
