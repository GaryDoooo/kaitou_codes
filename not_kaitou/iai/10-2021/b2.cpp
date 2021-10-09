#include <iostream>
using namespace std;
int main() {
    int n, m, res = 1;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % m;
    }
    cout << res;
}

