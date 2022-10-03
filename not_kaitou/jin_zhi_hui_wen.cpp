#include <iostream>
#include <string>
#include <set>
#include <algorithm>
// #include<bits/stdc++.h>
using namespace std;

string convert(int x, int base) {
    string itos = "0123456789abcdef";
    return (x > 0 ? convert(x / base, base) + itos[x % base] : "");
}

int main() {
    set<int> res;
    int x;
    cin >> x;
    for (int base = 2; base <= 16; ++base) {
        string s1 = convert(x,  base);
        string s2(s1.rbegin(), s1.rend());
        if (s1 == s2) res.insert(base);
    }
    cout << (res.size() == 0 ? "No" : "Yes") << endl;
    for (auto i : res) cout << i << " ";
    return 0;
}