#include <bits/stdc++.h>
using namespace std;
bool OK(string const &s) {
    if (s.length() < 3) return true;
    for (int i = 1; i <= s.length() / 3; i++) {
        string s1 = s.substr(0, i), s2 = s.substr(i, i), s3 = s.substr(i << 1, i);
        if (s1 == s2 and s2 == s3) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n ;
    unordered_set<string> slist, temp;
    slist.insert("");
    for (int i = 1; i <= n; i++) {
        temp.clear();
        for (auto s : slist) {
            string new_str = '1' + s;
            if (OK(new_str)) temp.insert(new_str);
            new_str = '0' + s;
            if (OK(new_str)) temp.insert(new_str);
        }
        swap(temp, slist);
    }
    cout << slist.size() << endl;
    // return slist.size();
}
// int main() {
//     for (int i = 1; i <= 40; i++) {
//         printf("%d,", main2(i));
//     } cout << endl;
// }