#include <bits/stdc++.h>
using namespace std;
unsigned long to_dec(int base, string n) {
    unsigned long res = 0;
    for (auto i = 0; i < n.size(); i++) {
        char c = n[i];
        res = res * base + (c - '0');
    }
    return res;
}
int main() {
    int base;
    string n;
    cin >> base >> n;
    unsigned long a = to_dec(base, n);
    cin >> base >> n;
    unsigned long b = to_dec(base, n);
    if (a > b)
        cout << "x>y";
    else if (a < b)
        cout << "x<y";
    else
        cout << "x=y";
    return 0;
}