#include <iostream>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    for (int i = 1; i <= n / 2; i++) {
        cin >> a;
        cout << a * 2 << " ";
    }
    for (int i = 1; i <= n / 2; i++) {
        cin >> a;
        cout << a + 1 << " ";
    }
}
