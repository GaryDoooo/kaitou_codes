#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long sum = 0, a = 0, sign = 1;
    for (unsigned int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '+' || c == '-') {
            sum += a * sign;
            if (c == '-') sign = -1;
            else sign = 1;
            a = 0;
        } else {
            a = a * 10 + (int)(c - 'a');
        }
    }
    sum += a * sign;
    cout << sum << endl;
    return 0;
}