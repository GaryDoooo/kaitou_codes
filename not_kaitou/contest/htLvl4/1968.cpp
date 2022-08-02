#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    unsigned long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += (n / i) * i;
    }
    cout << res << endl;
}

