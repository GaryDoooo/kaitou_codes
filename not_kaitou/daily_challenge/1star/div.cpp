#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int d[4] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++) {
        if (n % d[i] == 0) cout << d[i] << endl;
    }
}
