#include <iostream>
#include <string>
#include <algorithm>
#include <map>
// #include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> m;
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i++) m[s.substr(i - 1, 2)]++;
    int max_count = 0;
    for (auto i : m) max_count = max(max_count, i.second);
    for (auto i : m) if (i.second == max_count) cout << i.first << endl;
}