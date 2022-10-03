#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    for (int i = 1; i <= 18; i++) {
        for (int j = i; j <= 18; j++) {
            for (int k = j; k <= 18; k++) {
                if (i * j * k == 18) ans ++;
            }
        }
    }
    cout << ans << endl;
}