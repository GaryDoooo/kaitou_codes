#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    // cout << 'a' - 'A' << endl;
    cout << char(s[0] + 32);
    for (int i = 1; i < s.size(); i++) {
        char c = s[i];
        if (c <= 'Z')
            cout << "_" << char(c + 32);
        else
            cout << c;
    }
    cout << endl;
}
