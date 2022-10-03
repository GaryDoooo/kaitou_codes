#include <iostream>
using namespace std;

int main() {
    int a[11] = {0, 3, 2, 5, 4, 6, 1, 7, 5, 8, 9};
    int ans = 0;
    for (int i = 6; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            for (int k = j + 1; k <= 9; k++) {
                ans += a[j] + a[i] + a[k];
            }
        }
    }
    cout << ans;
    return 0;
}