#include <iostream>
using namespace std;
int main() {
    int a, x, y;
    cin >> a >> x >> y;
    for (int i = 1; i < 1e9; i++) {
        if (i * a - x == i * (a - 1) + y) {
            cout << i << " " << i * a - x;
            return 0;
        }
    }
}
