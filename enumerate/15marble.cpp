#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    for (int i = 1; i <= 15; i++) {
        for (int j = i + 1; j <= 15 - i; j++) {
            for (int k = j + 1; k <= 15 - j; k++) {
                if (15 - (i + j + k) > k) ans ++;
            }
        }
    }
    cout << ans;
}