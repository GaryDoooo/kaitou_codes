#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 2; j < i; j++) res += i % j == 0;
        cout << res << endl;
    }
}
