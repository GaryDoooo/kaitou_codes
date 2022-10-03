#include<bits/stdc++.h>
using namespace std;
int sync_number(string const &input) {
    // cout << input << endl;
    int c[input.size()];
    for (int i = 0; i < input.size(); i++) c[i] = input[i] - 'a';
    for (int i = input.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) c[j] = (c[j + 1] + c[j]) % 10;//, cout << c[j] << " ";
        // cout << endl;
    }
    return c[0];
}
int main() {
    string name1, name2;
    cin >> name1 >> name2;
    cout << max(sync_number(name1 + name2), sync_number(name2 + name1)) << endl;
    return 0;
}