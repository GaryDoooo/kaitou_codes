#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     res.push_back(i);
    //     reverse(res.begin(), res.end());
    // }
    int e = n + 2;
    bool sub = true;
    bool a1 = false;
    bool odd = (n % 2 == 1);
    for (int i = 0; i < n; i++) {
        if (sub and e - 2 <= 1) {
            sub = false;
            a1 = true;
            e = 1;
        } else if (sub) {
            e -= 2;
        } else if (a1 and odd) {
            e++;
            a1 = false;
        } else if (not sub) {
            e += 2;
        }
        cout << e << " ";
    }
    // for (auto i : res) cout << i << " ";
    return 0;
}