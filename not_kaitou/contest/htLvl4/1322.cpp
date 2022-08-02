#include <iostream>
using namespace std;
int main() {
    int n;
    double s = 1, res = 0;
    cin >> n;
    while (1) {
        res += 1 / s;
        if (res > n) {
            cout << int(s) << endl;
            return 0;
        }
        s += 1;
    }
}

