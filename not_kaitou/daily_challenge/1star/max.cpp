#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a, res[n], index = 0, m = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a > m) {
            m      = a;
            index  = 1;
            res[0] = i;
        } else if (a == m) {
            res[index++] = i;
        }
    }
    for (int i = 0; i < index; i++) cout << res[i] << endl;
}

