#include <bits/stdc++.h>
using namespace std;
unsigned int o[100000] = {0}, a[100000];
int calc(int begin, int end) {
    if (end < begin) return a[begin];
    int i = min_element(o + begin, o + end) - o;
    int left = calc(begin, i - 1) % 10000, right = calc(i + 1, end) % 10000;
    // cout << begin << " " << end << " " << i << " " << left << " " << right << endl;
    if (o[i] == 1) return (left + right) % 10000;
    else if (o[i] == 2) return (left * right) % 10000;
    else return left;
}
int main() {
    string s;
    cin >> s;
    unsigned long long num = 0, index = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '+') o[index] = 1, a[index++] = num % 10000, num = 0;
        else if (s[i] == '*') o[index] = 2, a[index++] = num % 10000, num = 0;
        else num = num * 10 + (int)(s[i] - '0');
    }
    a[index] = num % 10000;
    // cout << index << endl;
    // for (unsigned int i = 0; i <= index; i++) cout << a[i] << " " << o[i] << endl;
    cout << calc(0, index);
}