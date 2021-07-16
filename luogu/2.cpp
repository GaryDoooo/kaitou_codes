#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 2000; i <= n; i++) {
        int a = n / 1000;
        int b = n / 100 % 10;
        int c = n / 10 % 10;
        int d = n % 10;
        if (((a * 10 + b) + (c * 10 + d)) * ((a * 10 + b) + (c * 10 + d))) {
            cout << a << b << c << d << endl;
            return 0;
        }
    }
    cout << "No";
    return 0;
}