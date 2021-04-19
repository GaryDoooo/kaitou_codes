#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int max = 0;
    for (int i = 0; i < n / 2; i++) {
        if (a[i] + a[n - 1 - i] > max) max = a[i] + a[n - 1 - i];
    }
    cout << max << endl;
}
