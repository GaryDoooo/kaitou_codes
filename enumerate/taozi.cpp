#include <iostream>
using namespace std;
int main() {
    int ans = 2;
    for (int i = 0; i < 3; i++) {
        ans = (ans + 1) * 2;
    }
    cout << ans << endl;
}