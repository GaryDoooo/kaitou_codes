#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1000; i <= n; i++) {
        int a = i / 1000;
        int b = i / 100 % 10;
        int c = i / 10 % 10;
        int d = i % 10;
        if (((a * 10 + b) + (c * 10 + d)) * ((a * 10 + b) + (c * 10 + d))) {
            cout << a << b << c << d << endl;
            return 0;
        }
    }
    cout << "No";
    return 0;
}