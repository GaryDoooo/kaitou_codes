#include <iostream>
using namespace std;
int a[10005], i, n;
int main() {
    cin >> n;
    int j = 0;
    for (i = 1; ; i++) {
        for (int k = 0; k < i; k++) {
            a[++j] = i;
        }
        if (j >= n) {
            break;
        }
    }
    j = 0;
    for (int k = 1; k <= n; k++) {
        j += a[k];
    }
    cout << j << endl;
}
