#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i = n;
    while (i > 0) {
        cout << i << " ";
        i -= 2;
    }
    i = 2 - (i == 0);
    while (i < n) {
        cout << i << " ";
        i += 2;
    }
    return 0;
}
