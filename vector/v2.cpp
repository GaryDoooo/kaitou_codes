#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// vector<int> operator<<(const vector<int> &v) {
//     for (auto i : v) cout << i << " ";
//     cout << endl;
// }
ostream &operator<<(ostream &s, const vector<int> &p) {
    for (auto i : p) s << i << " ";
    s << endl;
    return NULL;
}

int main() {
    vector<int> v(4);
    cout << v;
}