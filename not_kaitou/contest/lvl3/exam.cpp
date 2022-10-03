#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << n - (n / a + n / b + n / c - n / lcm(a, b) - n / lcm(b, c) -
                 n / lcm(c, a) + n / lcm(a, lcm(b, c)));
}
