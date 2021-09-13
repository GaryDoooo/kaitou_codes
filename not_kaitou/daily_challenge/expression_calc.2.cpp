#include <bits/stdc++.h>
using namespace std;
unsigned int a[100000] = {0};
int main() {
    string s;
    cin >> s;
    unsigned long long num = 0, index = 0, has_multiple = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (int)(s[i] - '0');
        } else {
            if (has_multiple) a[index] = (num % 10000) * a[index] % 10000, num = 0;
            else a[++index] = num % 10000, num = 0;
            has_multiple = (s[i] == '*');
        }
    }
    if (has_multiple) a[index] = (num % 10000) * a[index] % 10000;
    else a[++index] = num % 10000;
    int res = 0;
    for (unsigned int i = 0; i <= index; i++) res = (res + a[i]) % 10000;
    // a[index] = num % 10000;
    // cout << index << endl;
    // for (unsigned int i = 0; i <= index; i++) cout << a[i] << " " << o[i] << endl;
    // cout << calc(0, index);
    cout << res;
}