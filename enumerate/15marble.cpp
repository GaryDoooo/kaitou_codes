#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    for (int i = 1; i <= 15; i++) {
        for (int j = i + 1; j <= 15 - i; j++) {
            for (int k = j + 1; k <= 15 - j; k++) {
                if (k > j) ans ++;
            }
        }
    }
    cout << ans;
}