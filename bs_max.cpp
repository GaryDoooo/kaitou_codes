#include <iostream>
using namespace std;

double f(double x) { return -x * x + 3 * x + 4; }

int main() {
    // for (double i = 0; i < 10; i += 0.1) {
    //     cout << f(i) << " ";
    // }
    double k;
    // for (int ii = 0; ii < 3000000; ii++) {
    // Binary search
    k = -10;
    for (double j = 1; j >= 0.01; j /= 2) {
        while (f(k + j) < f(k + j + 0.01)) {
            k += j;
            cout << "k=" << k << " j=" << j << endl;
        }
    }
    cout << k + 0.01 << endl;
    //////////////////////////
    // Brute Force
    double m = -10000;
    double i = 0;
    while (1) {
        if (f(i) > f(i + 0.01)) {
            cout << i << endl;
            break;
        }
        i += 0.01;
    }
    // }
}
