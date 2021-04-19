#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = i + 1; j <= 13; j++) {
            for (int k = j + 1; k <= 14; k++) {
                if (k > j) ans ++;
            }
        }
    }
    cout << ans;
}