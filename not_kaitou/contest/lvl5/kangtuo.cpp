#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int dia_cnt = a + b - 1;
    int res     = dia_cnt * (dia_cnt - 1) / 2;
    if (dia_cnt & 1) {
        cout << res + b;
    } else {
        cout << res + a;
    }
}
