#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

vector<int> parse(string s) {
    map<char, int> c;
    vector<int> res;
    for (int i = 0; i < 10; i++) c[48 + i] = i;
    for (int i = 0; i < 6; i++) c[65 + i] = 10 + i;
    for (int i = s.length() - 1; i >= 0; i--) {
        char ch = s[i];
        res.push_back(c[ch]);
    }
    return res;
}

vector<int> add(vector<int> &a, int n) {
    vector<int> res = {};
    int re = 0;
    vector<int> r (a.rbegin(), a.rend());
    for (int i = a.size() - 1; i >= 0; i--) {
        int s = a[i] + r[i] + re;
        re = s / n;
        res.push_back(s % n);
    }
    if (re != 0) res.push_back(re);
    return res;
}

bool hui(vector<int> &a) {
    vector<int> r (a.rbegin(), a.rend());
    return (a == r);
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    a = parse(s);
    // for (auto i : add(a, 10)) cout << i << " ";
    // cout << endl;
    for (auto i = 0; i < 30; i++) {
        vector<int> b = add(a, n);
        if (hui(b)) {cout << "STEP=" << i + 1 << endl; return 0;}
        a = b;
    }
    cout << "Impossible!" << endl;
    return 0;
}