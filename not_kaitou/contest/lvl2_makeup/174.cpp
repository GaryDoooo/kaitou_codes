#include <iostream>
using namespace std;
int a, n, ro, re;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a & 1)
            ro += a;
        else
            re += a;
    }
    cout << ro << endl << re << endl;
}
