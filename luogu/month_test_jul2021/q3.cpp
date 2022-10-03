#include <iostream>
#include <vector>
using namespace std;

vector<int> convert_to_base(long long n, int base) {
    vector <int> res = {};
    while (n >= 1) {
        res.push_back(n % base);
        n /= base;
    }
    // if (res.() == 0) {
    //     res.erase(res.begin());
    // }
    return res;
}
bool hui(vector<int> &a) {
    vector<int> r (a.rbegin(), a.rend());
    return (a == r);
}
int main() {
    long long x;
    cin >> x;
    vector<int> e = convert_to_base(x, 2);
    // if (hui(e)) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }
    bool fl = true;
    for (int i = 2; i <= 16; i++ ) {
        e = convert_to_base(x, i);
        // for (auto i : e) cout << i << " ";
        // cout << endl;
        if (hui(e)) {
            if (fl) {
                cout << "Yes" << endl;
                fl = false;
            }
            cout << i << " ";
        }
    }
    if (fl) {
        cout << "No";
    }
    return 0;
}