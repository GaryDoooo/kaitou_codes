#include <iostream>
using namespace std;
int main() {
    int n, res = 0;
    cin >> n;
    if (n <= 1000) {
        res = 12;
    } else {
        n -= 1000;
        res = 12 + ((n + 499) / 500) * 5;
    }
    cout << res;
}
