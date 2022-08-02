#include <iostream>
using namespace std;
int main() {
    int res = 0, n;
    cin >> n;
    while (n > 0) {
        int i = n % 10;
        res += i * i * i;
        n /= 10;
    }
    cout << res << endl;
}
