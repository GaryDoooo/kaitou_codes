#include <bits/stdc++.h>
using namespace std;
string convert(string const &a, string const &b) {
    if (a.length() == 0) return "";
    char mid         = a[0];
    int mid_pos_in_b = b.find(mid);
    int left_len = mid_pos_in_b, right_len = b.length() - mid_pos_in_b - 1;
    string res = convert(a.substr(1, left_len), b.substr(0, left_len));
    res += convert(a.substr(left_len + 1, right_len),
                   b.substr(mid_pos_in_b + 1, right_len));
    res.push_back(mid);
    return res;
}
int main() {
    string a, b;
    cin >> a >> b;
    cout << convert(a, b);
}
