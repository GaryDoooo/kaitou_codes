#include <iostream>
using namespace std;
int a[10000], m;
int main() {
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    if (m & 1) {
        for (int i = 1; i <= m; i++) cout << a[i] << " ";
    } else {
        for (int i = m; i > 0; i--) cout << a[i] << " ";
    }
}

