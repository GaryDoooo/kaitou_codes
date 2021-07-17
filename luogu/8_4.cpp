#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j >= 1; j--) {
            for (int k = 0; k < j; k++) {
                cout << i;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}